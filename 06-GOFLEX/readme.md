TEST testGral.go
Palabra reservada (definicion): package
Identificador: main
Palabra reservada (definicion): func
Identificador: main
Caracter de puntuacion: (
Caracter de puntuacion: )
Caracter de puntuacion: {
Palabra reservada (tipo de dato): int
Operador: =
Constante entera decimal: 42
Palabra reservada (definicion): var
Identificador: decimal
Palabra reservada (tipo de dato): float32
Operador: =
Constante real: 3.14
Identificador: f
Palabra reservada (definicion): var
Identificador: letra
Palabra reservada (tipo de dato): rune
Operador: =
Constante caracter: 'A'
Palabra reservada (definicion): var
Identificador: grande
Palabra reservada (tipo de dato): float64
Operador: =
Constante real: 1.23e+10
Palabra reservada (definicion): var
Identificador: contador
Palabra reservada (tipo de dato): int
Operador: =
Constante entera decimal: 0755
Identificador: hex
Caracter de puntuacion: .
Operador: =
Constante entera hexadecimal: 0xFF
Palabra reservada (definicion): var
Identificador: real
Palabra reservada (tipo de dato): float64
Operador: =
Constante real: 0.001
Palabra reservada (definicion): var
Identificador: _variable1
Palabra reservada (tipo de dato): int
Operador: =
Constante entera decimal: 10
Palabra reservada (definicion): var
Identificador: promedio_final
Palabra reservada (tipo de dato): float32
Operador: =
Constante real: 8.75
Identificador: f
Palabra reservada (definicion): var
Identificador: activo
Palabra reservada (tipo de dato): bool
Operador: =
Identificador: true
Palabra reservada (definicion): var
Identificador: i
Palabra reservada (tipo de dato): int
Palabra reservada (control): if
Operador: !
Identificador: numero
Operador: >=
Identificador: promedioFinal
Operador: &&
Identificador: activo
Operador: !=
Identificador: false
Caracter de puntuacion: {
Identificador: numero
Operador: +=
Constante entera decimal: 1
Caracter de puntuacion: }
Caracter de puntuacion: ;
Palabra reservada (control): for
Identificador: i
Operador: =
Constante entera decimal: 0
Caracter de puntuacion: ;
Identificador: i
Operador: <
Constante entera decimal: 10
Caracter de puntuacion: ;
Identificador: i
Operador: ++
Caracter de puntuacion: {
Identificador: fmt
Caracter de puntuacion: .
Identificador: Printf
Caracter de puntuacion: (
Literal cadena: "Iteraci├│n %d\n"
Caracter de puntuacion: ,
Identificador: i
Caracter de puntuacion: )
Identificador: i
Operador: -=
Constante entera decimal: 1
Caracter de puntuacion: }
Palabra reservada (definicion): const
Identificador: mensaje
Palabra reservada (tipo de dato): string
Operador: =
Literal cadena: "Hola mundo"
Palabra reservada (control): return
Constante entera decimal: 0
Caracter de puntuacion: }

TEST testIdCharStr.go
Constante caracter: 'a'
Constante caracter: '\n'
Error lexico: '
Error lexico: \
Identificador: x41
Error lexico: '
Literal cadena: "hola"
Literal cadena: "con escape \"comillas\""
Literal cadena: "linea\nnueva"
Identificador: variable
Identificador: _variable
Identificador: miVariable123
Identificador: x9
Identificador: a


TEST testNum.go
Constante entera decimal: 0
Constante entera decimal: 123
Constante entera decimal: 007
Constante entera decimal: 0755
Constante entera hexadecimal: 0xFF
Constante entera hexadecimal: 0X1a3
Constante real: 12.34
Constante real: 0.5
Operador: -
Constante real: 3.14
Constante real: 10.5e10
Constante real: 2.71E-5
Constante real: 0.0
Operador: -
Constante entera decimal: 2
Identificador: e
Constante entera decimal: 5
Caracter de puntuacion: .
Caracter de puntuacion: .
Constante entera decimal: 5
Constante entera decimal: 1
Identificador: e3
Operador: -
Constante entera decimal: 2
Constante entera decimal: 00
Constante entera hexadecimal: 0x0
Constante entera decimal: 0
Identificador: x


TEST testResOpBool.go
Palabra reservada (definicion): package
Identificador: main
Palabra reservada (definicion): import
Literal cadena: "fmt"
Palabra reservada (definicion): func
Identificador: main
Caracter de puntuacion: (
Caracter de puntuacion: )
Caracter de puntuacion: {
Palabra reservada (definicion): var
Identificador: x
Palabra reservada (tipo de dato): int
Operador: =
Constante entera decimal: 5
Palabra reservada (definicion): var
Identificador: decimal
Palabra reservada (tipo de dato): float64
Operador: =
Constante real: 3.14
Palabra reservada (definicion): var
Identificador: letra
Palabra reservada (tipo de dato): rune
Operador: =
Constante caracter: 'A'
Palabra reservada (definicion): var
Identificador: grande
Palabra reservada (tipo de dato): float64
Operador: =
Constante real: 1.23e+10
Palabra reservada (definicion): var
Identificador: contador
Palabra reservada (tipo de dato): int
Operador: =
Constante entera decimal: 0
Identificador: o755
Palabra reservada (definicion): var
Identificador: real
Palabra reservada (tipo de dato): float64
Operador: =
Constante real: 0.001
Palabra reservada (definicion): var
Identificador: variable1
Palabra reservada (tipo de dato): int
Operador: =
Constante entera decimal: 10
Palabra reservada (definicion): var
Identificador: promedioFinal
Palabra reservada (tipo de dato): float64
Operador: =
Constante real: 8.75
Palabra reservada (definicion): var
Identificador: activo
Palabra reservada (tipo de dato): bool
Operador: =
Identificador: true
Palabra reservada (definicion): var
Identificador: i
Palabra reservada (tipo de dato): int
Operador: /
Operador: /
Palabra reservada (control): if
Operador: /
Palabra reservada (control): else
Identificador: v
Error lexico: ├
Error lexico: í
Identificador: lido
Palabra reservada (control): if
Identificador: x
Operador: ==
Identificador: contador
Caracter de puntuacion: {
Identificador: x
Operador: +=
Constante entera decimal: 2
Caracter de puntuacion: }
Palabra reservada (control): else
Caracter de puntuacion: {
Identificador: contador
Operador: --
Caracter de puntuacion: }
Operador: /
Operador: /
Literal cadena: "while"
Identificador: usando
Palabra reservada (control): for
Palabra reservada (control): for
Identificador: x
Operador: >
Identificador: contador
Operador: &&
Identificador: x
Operador: <
Constante entera decimal: 100
Caracter de puntuacion: {
Identificador: x
Operador: =
Identificador: x
Operador: -
Constante entera decimal: 1
Caracter de puntuacion: }
Operador: /
Operador: /
Palabra reservada (control): for
Palabra reservada (control): for
Identificador: i
Operador: =
Constante entera decimal: 0
Caracter de puntuacion: ;
Identificador: i
Operador: <
Constante entera decimal: 10
Caracter de puntuacion: ;
Identificador: i
Operador: ++
Caracter de puntuacion: {
Identificador: fmt
Caracter de puntuacion: .
Identificador: Printf
Caracter de puntuacion: (
Literal cadena: "Iteraci├│n %d\n"
Caracter de puntuacion: ,
Identificador: i
Caracter de puntuacion: )
Identificador: i
Operador: -=
Constante entera decimal: 1
Caracter de puntuacion: }
Palabra reservada (definicion): const
Identificador: mensaje
Palabra reservada (tipo de dato): string
Operador: =
Literal cadena: "Hola mundo"
Palabra reservada (definicion): var
Identificador: resultado
Palabra reservada (tipo de dato): int
Palabra reservada (control): if
Identificador: activo
Caracter de puntuacion: {
Identificador: resultado
Operador: =
Constante entera decimal: 1
Caracter de puntuacion: }
Palabra reservada (control): else
Caracter de puntuacion: {
Identificador: resultado
Operador: =
Constante entera decimal: 0
Caracter de puntuacion: }
Identificador: fmt
Caracter de puntuacion: .
Identificador: Println
Caracter de puntuacion: (
Literal cadena: "Resultado:"
Caracter de puntuacion: ,
Identificador: resultado
Caracter de puntuacion: )
Caracter de puntuacion: }
