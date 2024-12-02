# Comando: echo
**Descripción:** Imprime texto o el valor de una variable en la terminal.

**Ejemplo:**
```bash
echo "Hola, Mundo"
```
**Salida:**
```
Hola, Mundo
```

# Comando: grep -E <expresión regular> <archivo>
**Descripción:** Busca patrones dentro de un archivo usando expresiones regulares extendidas.

**Ejemplo:**
```bash
grep -E "a|e" archivo.txt
```
**Salida:**
```
apple
banana
cherry
grape
```

# Comando: head <archivo>
**Descripción:** Muestra las primeras 10 líneas de un archivo.

**Ejemplo:**
```bash
head archivo.txt
```
**Salida:**
```
linea1
linea2
linea3
linea4
linea5
linea6
linea7
linea8
linea9
linea10
```

# Comando: tail <archivo>
**Descripción:** Muestra las últimas 10 líneas de un archivo.

**Ejemplo:**
```bash
tail archivo.txt
```
**Salida:**
```
linea2
linea3
linea4
linea5
linea6
linea7
linea8
linea9
linea10
linea11
```

# Comando: more <archivo>
**Descripción:** Muestra el contenido de un archivo página por página.

**Ejemplo:**
```bash
more archivo.txt
```


# Comando: sort -R <archivo>

**Descripción:** se utiliza para ordenar aleatoriamente las líneas de un archivo o entrada. Es decir, reorganiza las líneas en un orden completamente aleatorio


**Sintaxis básica:**
```bash
sort -R <archivo>
```

# Comando: awk '{ print tolower($0) }' archivo.txt > archivo_minusculas.txt

# Comando: wc -l archivo.txt 


# Compilacion con -Wall