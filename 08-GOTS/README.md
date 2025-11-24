# Casos de Prueba

## 1. Pruebas Lexicas

### testLexico_caracterInvalido.go
**Objetivo**: Verificar que el analizador lexico detecta caracteres invalidos.

**Contenido**:
```go
package main

func main() {
    if x > 3 @@{
        x = 10
    }
}
```

**Salida esperada**:
```
Error lexico <linea:4 columna:14> Caracter no valido: '@'
Error lexico <linea:4 columna:15> Caracter no valido: '@'
Se encontraron 2 errores lexicos
```

---

## 2. Pruebas Sintacticas

### testSintactico_faltaLlave.go
**Objetivo**: Verificar deteccion que falta de llaves de apertura.

**Salida esperada**:
```
Error sintactico en linea 7, columna 4: syntax error
[El parser se detiene en el primer error encontrado]
```

---

## 3. Pruebas Semanticas

### testSemantico1_variablesNoDeclaradas.go
**Objetivo**: Detectar uso de variables no declaradas.

**Salida esperada**:
```
Error semantico [linea 5, columna 9]: Variable no declarada: 'z'
Error semantico [linea 7, columna 7]: Variable no declarada: 'w'
Se encontraron:
  - 2 error(es) semantico(s)
```

### testSemantico2_dobleDeclaracion.go
**Objetivo**: Detectar redeclaracion de variables y constantes.

**Salida esperada**:
```
Error semantico [linea 5]: Redeclaracion de 'x'
Error semantico [linea 8]: Redeclaracion de 'PI'
Error semantico [linea 13]: Redeclaracion de 'y' con :=
Se encontraron:
  - 3 error(es) semantico(s)
```

### testSemantico3_tiposIncompatibles.go
**Objetivo**: Detectar asignaciones con tipos incompatibles.

**Salida esperada**:
```
Error semantico [linea 7]: Tipos incompatibles en asignacion
Error semantico [linea 15]: Tipos incompatibles en asignacion
Error semantico [linea 17]: Tipos incompatibles en operacion +=
Se encontraron:
  - 3 error(es) semantico(s)
```

## 4. Pruebas Validas

### testValido_simple.go
**Objetivo**: Verificar analisis exitoso de programa minimo valido.

**Salida esperada**:
```
Analisis completado exitosamente.

```

### testValido_completo.go
**Objetivo**: Verificar analisis exitoso de programa con multiples features.

**Salida esperada**:
```
Analisis completado exitosamente.

```


