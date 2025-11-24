# Compilación

## Makefile
```bash
make
```

## Limpiar
```bash
make clean
```

## Uso
```bash
./parser <archivo.go>
```

# Casos de Prueba

## 1. Pruebas Válidas

### archivoValido.go
**Objetivo**: Verificar análisis exitoso de programa mínimo válido.

**Contenido**:
```go
package main

func main() {
    var x int = 5
    var y int = 10
    return
}
```

**Salida esperada**:
```
Análisis completado exitosamente.
```

---

### test.go
**Objetivo**: Verificar declaraciones globales (variables y constantes) con función main.

**Salida esperada**:
```
Análisis completado exitosamente.
```

---

### archivoValido2.go
**Objetivo**: Verificar programa completo con múltiples características (enums, funciones, bucles, condicionales).

**Salida esperada**:
```
Análisis completado exitosamente.
```

---

## 2. Pruebas Inválidas

### archivoInvalido.go
**Objetivo**: Detectar múltiples errores sintácticos.

**Errores contenidos**:
- Línea 6: Falta llave `{` en función
- Línea 16: Falta llave `{` después de `if`
- Línea 21: Falta llave `}` en bucle `for`
- Línea 22: Falta `;` en declaración del `for`
- Línea 26: Paréntesis sin cerrar
- Línea 30: Falta expresión después de `=`

**Salida esperada**:
```
Error sintáctico en línea 6, columna X: syntax error, unexpected RETURN, expecting '{'
Se encontraron 1 errores.
```

---

### archivoInvalido2.go
**Objetivo**: Detectar falta de llave de apertura en `if`.

**Contenido**:
```go
package main

func main() {
    if x > 3
        x = 10
    }
}
```

**Salida esperada**:
```
Error sintáctico en línea 5, columna X: syntax error, unexpected IDENTIFICADOR, expecting '{'
Se encontraron 1 errores.
```