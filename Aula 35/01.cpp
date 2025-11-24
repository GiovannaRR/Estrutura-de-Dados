//1) Implemente a função remover completa, incluindo a lógica espelhada do fixDelete para o caso ”X  ́e filho direito”.

// Auxiliar necessário para a remoção (Move subárvores)
void transplant(Vertice* u, Vertice* v) {
    if (u->pai == nil) {
        raiz = v;
    } else if (u == u->pai->esq) {
        u->pai->esq = v;
    } else {
        u->pai->dir = v;
    }
    v->pai = u->pai;
}

// A lógica de correção (Fase 2)
void fixDelete(Vertice* x) {
    while (x != raiz && x->cor == PRETO) {
        
        // SE x É FILHO ESQUERDO 
        if (x == x->pai->esq) {
            Vertice* w = x->pai->dir; // Irmão da direita

            if (w->cor == VERMELHO) { // Caso 1
                w->cor = PRETO;
                x->pai->cor = VERMELHO;
                rot_esq(x->pai);
                w = x->pai->dir;
            }

            if (w->esq->cor == PRETO && w->dir->cor == PRETO) { // Caso 2
                w->cor = VERMELHO;
                x = x->pai;
            } else {
                if (w->dir->cor == PRETO) { // Caso 3
                    w->esq->cor = PRETO;
                    w->cor = VERMELHO;
                    rot_dir(w);
                    w = x->pai->dir;
                }
                // Caso 4
                w->cor = x->pai->cor;
                x->pai->cor = PRETO;
                w->dir->cor = PRETO;
                rot_esq(x->pai);
                x = raiz;
            }
        } 

        // Lógica espelhada (x é filho direito)
        else {
            Vertice* w = x->pai->esq; // O irmão agora é o da ESQUERDA

            // Caso 1 Simétrico: Irmão Vermelho
            if (w->cor == VERMELHO) {
                w->cor = PRETO;
                x->pai->cor = VERMELHO;
                rot_dir(x->pai); // Rotação invertida (Direita)
                w = x->pai->esq;
            }

            // Caso 2 Simétrico: Irmão Preto e ambos sobrinhos Pretos
            if (w->dir->cor == PRETO && w->esq->cor == PRETO) {
                w->cor = VERMELHO;
                x = x->pai; // O problema sobe
            } 
            else {
                // Caso 3 Simétrico: Sobrinho "próximo" (Direita de w) é Vermelho
                if (w->esq->cor == PRETO) {
                    w->dir->cor = PRETO;
                    w->cor = VERMELHO;
                    rot_esq(w); // Rotação invertida (Esquerda no irmão)
                    w = x->pai->esq;
                }
                // Caso 4 Simétrico: Sobrinho "distante" (Esquerda de w) é Vermelho
                w->cor = x->pai->cor;
                x->pai->cor = PRETO;
                w->esq->cor = PRETO;
                rot_dir(x->pai); // Rotação invertida (Direita no pai)
                x = raiz; 
            }
        }
    }
    x->cor = PRETO;
}


void remover(int valor) {
    Vertice* z = raiz;
    // Busca o nó
    while (z != nil) {
        if (valor == z->key) break;
        if (valor < z->key) z = z->esq;
        else z = z->dir;
    }
    if (z == nil) return; // Não encontrou

    Vertice* y = z; 
    Vertice* x;
    Cor cor_original_y = y->cor;

    if (z->esq == nil) {
        x = z->dir;
        transplant(z, z->dir);
    } else if (z->dir == nil) {
        x = z->esq;
        transplant(z, z->esq);
    } else {
        // Caso com 2 filhos: busca sucessor (minimo da direita)
        y = z->dir;
        while (y->esq != nil) y = y->esq;
        
        cor_original_y = y->cor;
        x = y->dir;

        if (y->pai == z) {
            x->pai = y;
        } else {
            transplant(y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }
        transplant(z, y);
        y->esq = z->esq;
        y->esq->pai = y;
        y->cor = z->cor;
    }
    
    delete z;

    // Se o nó removido (ou movido) era PRETO, precisamos corrigir
    if (cor_original_y == PRETO) {
        fixDelete(x);
    }
}