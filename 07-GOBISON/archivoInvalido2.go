package main

func main() {
    
    var i int
    var sum@ int   // error: identificador inválido con '@'

    for i = 0; i < 10; i++ {
        suma += i   // error: variable 'suma' no declarada
    }    

    return 0       // error: en Go 'main' no retorna valores
}
