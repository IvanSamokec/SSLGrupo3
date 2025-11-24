# Compilación

## Linux/Mac/Windows
```bash
make
```

## Limpiar
```bash
make clean
```

## Uso
```bash
./lexer <archivo.go>
```

## Casos de Prueba

### 1. Pruebas de Números

### testNum.go
**Objetivo**: Verificar reconocimiento de constantes numéricas (decimales, octales, hexadecimales y reales).

**Contenido**:
```go
0
123
007
0755
0xFF
0X1a3
12.34
0.5
10.5e10
2.71E-5
```

**Salida esperada**:
```
Constante entera decimal: 0
Constante entera decimal: 123
Constante entera octal: 007
Constante entera octal: 0755
Constante entera hexadecimal: 0xFF
Constante entera hexadecimal: 0X1a3
Constante real: 12.34
Constante real: 0.5
Constante real: 10.5e10
Constante real: 2.71E-5
```

**Casos inválidos detectados**:
```
Error lexico: -
Error lexico: .
```

---

### 2. Pruebas de Identificadores, Caracteres y Cadenas

### testIdCharStr.go
**Objetivo**: Verificar reconocimiento de caracteres, cadenas e identificadores.

**Contenido**:
```go
'a'
'\n'
'\x41'
"hola"
"con escape \"comillas\""
"linea\nnueva"
variable
_variable
miVariable123
x9
a
```

**Salida esperada**:
```
Constante caracter: 'a'
Constante caracter: '\n'
Constante caracter: '\x41'
Literal cadena: "hola"
Literal cadena: "con escape \"comillas\""
Literal cadena: "linea\nnueva"
Identificador: variable
Identificador: _variable
Identificador: miVariable123
Identificador: x9
Identificador: a
```

---

### 3. Pruebas de Palabras Reservadas, Operadores y Booleanos

### testResOpBool.go
**Objetivo**: Verificar reconocimiento de palabras reservadas, operadores, estructuras de control y expresiones completas.

**Contenido**: Ver archivo completo en el repositorio.

**Categorías reconocidas**:
- Palabras reservadas (definición): `package`, `import`, `func`, `var`, `const`
- Palabras reservadas (tipo de dato): `int`, `float64`, `rune`, `bool`, `string`
- Palabras reservadas (control): `if`, `else`, `for`, `return`, `break`, `continue`
- Operadores: `=`, `+=`, `--`, `==`, `&&`, `<`, `>`, `-=`
- Identificadores y literales
- Caracteres de puntuación: `{`, `}`, `(`, `)`, `,`, `;`

**Salida esperada**: Reconocimiento correcto de todas las categorías léxicas sin errores.

---

### 4. Casos con Errores Léxicos

**Objetivo**: Detectar caracteres no válidos en el lenguaje Go.

**Ejemplos de errores**:
- Operador `-` aislado sin formar parte de un número
- Punto `.` aislado sin formar parte de un número real
- Caracteres especiales no reconocidos

**Salida esperada**:
```
Error lexico: <caracter_invalido>
```