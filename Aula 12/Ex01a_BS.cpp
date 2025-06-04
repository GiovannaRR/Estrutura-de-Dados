// Rastreamento passo a passo
// a. Bubble Sort (versão otimizada)

// entrada: A = <7, 3, 9, 2, 5>

// i = 0
// comparações: (7, 3) (7, 9) (9, 2) (9, 5)
// trocas: (7, 3) (9, 2) (9, 5)
// final na primeira passagem: [3, 7, 2, 5, 9] 

// i = 1
// comparações: (3, 7) (7, 2) (7, 5) 
// trocas: (7, 2) (7, 5)
// final na segunda passagem: [3, 2, 5, 7, 9]

// i = 2
// comparações: (3, 2) (3, 5)
// trocas: (3, 2)
// final na terceira passagem: [2, 3, 5, 7, 9]

//i = 3
// comparações: (2, 3)
//trocas: não tem, break

// array final: [2, 3, 5, 7, 9]