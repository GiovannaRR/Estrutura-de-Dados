//1) No código do fixup apresentado, há um comentário // C ́odigo Simétrico. Escreva o pseudocódigo ou o código
// C++ completo para este bloco else, que trata o caso em queo pai  ́e o filho direito do avô.

else { // O pai é o filho DIREITO do avô
    Vertex* tio = avo->esq; // O tio é o irmão esquerdo do pai

    // Caso 1: Tio Vermelho
    // A lógica de recoloração é idêntica, independente do lado
    if (tio->cor == RED) {
        pai->cor = BLACK;
        tio->cor = BLACK;
        avo->cor = RED;
        z = avo; // O problema sobe para o avô
    }
    else {
        // Casos 2 e 3: Tio Preto

        // Caso 2: Joelho (Zig-Zag)
        // O pai é filho à direita, mas z é filho à esquerda
        if (z == pai->esq) {
            z = pai;
            rot_dir(z); // Rotação à Direita para transformar em Linha Reta
        }

        // Caso 3: Linha Reta
        // Configuração final: avô, pai e z formam uma linha caindo para a direita
        pai->cor = BLACK;
        avo->cor = RED;
        rot_esq(avo); // Rotação à Esquerda no avô
    }
}