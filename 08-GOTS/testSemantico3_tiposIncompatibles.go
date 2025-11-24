package main

func main() {
    var x int = 5
    var s string = "hola"
    
    x = s  // ERROR: tipo incompatible
    
    var a int = 10
    var b float64 = 3.14
    a = b  // ERROR: asignación incompatible
    
    var c bool = true
    x = c  // ERROR: bool a int
    
    x += s  // ERROR: operación incompatible
}