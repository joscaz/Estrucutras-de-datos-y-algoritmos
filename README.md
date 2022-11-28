# Estrucutras-de-datos-y-algoritmos
Curso TC1031 del Tecnologico de Monterrey

## Actividad 1.1
Calcula la complejidad computacional en el peor de los casos de la función F. Justifique cada uno de los cálculos.

## Actividad 1.3 (Evidencia)
Algoritmos de ordenamiento y búsqueda.

1. Abra el archivo de entrada llamado "bitacora.txt Download bitacora.txt" lealo y almacene los datos en un vector.
2. Ordene la información por fecha para la realización de las búsquedas.
3. Solicite al usuario las fechas de inicio y fin de búsqueda de información.
4. Despliegue los registros correspondientes a esas fechas.
5. Almacenar en un archivo el resultado del ordenamiento.

## Actividad 2.1
Cumple correctamente con las funcionalidades requeridas por parte de la actividad.
[La actividad se encuentra aquí](https://github.com/joscaz/Estrucutras-de-datos-y-algoritmos/blob/main/images/Actividad%20Act%202.1_Ejercicio%20con%20el%20TDA%20Lista.pdf)

## Actividad 2.2
De manera individual, implemente el TDA Lista Doblemente Enlazada estudiado en clase. Puede apoyarse en el proyecto desarrollado en clases donde se implementaron los TDA Lista con Arreglo y Lista Doblemente Enlazada.

## Actividad 2.3 (Evidencia)
Importancia y eficiencia del uso de las listas doblemente ligadas

1. Abra el archivo de entrada llamado "bitacora.txt Download bitacora.txt" lealo y almacene los datos en un vector.
2. Ordene la información por ip para la realización de las búsquedas.
3. Solicite al usuario las ips de inicio y fin de búsqueda de información.
4. Despliegue los registros correspondientes a esas ips.
5. Almacenar en un archivo el resultado del ordenamiento.

## Actividad 3.1
Implementacion de un BST

## Actividad 3.2
Árbol Heap: Implementando una fila priorizada (Priority Queue)

## Actividad 4.1
Grafo: sus representaciones y sus recorridos

## Actividad 4.3 (Evidencia Grafos)
Investigación y reflexión de la importancia y eficiencia del uso grafos.

1. Abra el archivo de entrada llamado "bitacora.txt Download bitacora.txtVista previa del documento" lealo y almacene los datos en en una lista de adyacencia organizada por dirección de ip origen (Formato del archivo bitacora.pdf Download Formato del archivo bitacora.pdfVista previa del documento).
2. Determine el fan-out de cada nodo (A Fan-out will be interpreted as a vertex with one "input" and multiple "outputs")
3. ¿Qué nodos tienen el mayor fan-out?
4. ¿En qué dirección ip presumiblemente se encuentra el boot master?

## Hash Tables
### Actividad 5.1 (Implementación individual de operaciones sobre conjuntos)
En forma individual diseña e implementa una tabla de dispersión que incluya su técnica de hashing así como el manejo de colisiones a través de dirección abierta y sondeo lineal.
- Quadratic
    - Descripcion:
          - Manejo de desbordamiento por sondeo cuadrático
    - Entrada:
          - Tabla hash y elementos a insertar
    - Salida:
          - Nada
    - Precondición:
          - Tabla hash válida
    - Postcondición:
          - Tabla hash modificada y válida

- Chain
    - Descripcion:
          - Manejo de desbordamiento por encadenamiento.
    - Entrada:
          - La tabla de dispersión e información adicional sobre los elemento a insertar.
    - Salida:
          - Nada
    - Precondición:
          - Tabla hash válida
    - Postcondición:
          - Tabla hash debidamente actualizada.

### Actividad 5.2 (Evidencia hash table)
1. Lea el archivo de entrada "bitacora.txt Download bitacora.txt" (Formato del archivo bitacora.pdf.
2. Crear una tabla hash cuya llave sea el dominio y cuyo valor sea un resumen de ese dominio. Este resumen deberá incluir, el número de accesos, así como las ips de ese dominio.
3. Realiza un método que dado un nombre de un dominio regrese el valor asociado a él desplegando la información de una manera adecuada.

El documento de reflexión deberá incluir de manera específica si el uso de SHA-256 es adecuado y suficiente para los propósitos propuestos así como sus ventajas, desventajas y otros tipos de uso del SHA-256, así como su complejidad computacional
