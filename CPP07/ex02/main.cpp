/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 10:19:41 by antuel            #+#    #+#             */
/*   Updated: 2026/08/06 12:28:23 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <ctime>
#include <stdlib.h>

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}




/*	IA TEST

#define SEPARATOR "========================================"

// Función auxiliar para imprimir arrays de cualquier tipo
template <typename T>
void printArray(const Array<T>& arr, const std::string& name) {
    std::cout << name << " (size " << arr.size() << "): ";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << SEPARATOR << std::endl;
    std::cout << "🧪 INICIANDO TESTS DE Array<T>" << std::endl;
    std::cout << SEPARATOR << std::endl << std::endl;

    // ============================================================
    // TEST 1: Constructor por defecto (array vacío)
    // ============================================================
    std::cout << "📌 TEST 1: Constructor por defecto (array vacío)" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    
    Array<int> emptyArr;
    std::cout << "Array vacío - size: " << emptyArr.size() << std::endl;
    
    // Intentar acceder a un array vacío debería lanzar excepción
    try {
        emptyArr[0] = 42;
        std::cout << "❌ ERROR: Debería haber lanzado excepción" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "✅ Excepción capturada correctamente: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // ============================================================
    // TEST 2: Constructor con tamaño e inicialización por defecto
    // ============================================================
    std::cout << "📌 TEST 2: Constructor con tamaño (inicialización por defecto)" << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    
    Array<int> defaultInit(5);
    std::cout << "Array de 5 ints inicializados por defecto:" << std::endl;
    printArray(defaultInit, "defaultInit");
    std::cout << "✅ Los ints deberían estar inicializados a 0" << std::endl;
    std::cout << std::endl;

    // ============================================================
    // TEST 3: Diferentes tipos de datos
    // ============================================================
    std::cout << "📌 TEST 3: Diferentes tipos de datos" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    
    // Test con strings
    Array<std::string> strArr(3);
    strArr[0] = "Hola";
    strArr[1] = "Mundo";
    strArr[2] = "42!";
    printArray(strArr, "strArr");
    
    // Test con doubles
    Array<double> doubleArr(5);
    for (size_t i = 0; i < doubleArr.size(); i++)
        doubleArr[i] = i * 1.5;
    printArray(doubleArr, "doubleArr");
    
    // Test con chars
    Array<char> charArr(4);
    charArr[0] = 'A';
    charArr[1] = 'B';
    charArr[2] = 'C';
    charArr[3] = 'D';
    printArray(charArr, "charArr");
    std::cout << std::endl;

    // ============================================================
    // TEST 4: Copia profunda (constructor de copia)
    // ============================================================
    std::cout << "📌 TEST 4: Copia profunda (constructor de copia)" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    
    Array<int> original(3);
    original[0] = 10;
    original[1] = 20;
    original[2] = 30;
    
    Array<int> copia(original);  // Constructor de copia
    
    std::cout << "Array original: ";
    printArray(original, "original");
    std::cout << "Array copia:   ";
    printArray(copia, "copia");
    
    // Modificar el original
    original[0] = 999;
    std::cout << "\n✏️  Modificando original[0] = 999" << std::endl;
    std::cout << "Original después: ";
    printArray(original, "original");
    std::cout << "Copia después:   ";
    printArray(copia, "copia");
    
    if (copia[0] == 10)
        std::cout << "✅ Copia profunda funcionó correctamente (copia no se modificó)" << std::endl;
    else
        std::cout << "❌ ERROR: La copia se modificó (copia superficial)" << std::endl;
    std::cout << std::endl;

    // ============================================================
    // TEST 5: Operador de asignación
    // ============================================================
    std::cout << "📌 TEST 5: Operador de asignación" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    
    Array<int> a(2);
    a[0] = 1;
    a[1] = 2;
    
    Array<int> b;  // Array vacío
    std::cout << "Antes de asignación:" << std::endl;
    printArray(a, "a");
    std::cout << "b (vacío) - size: " << b.size() << std::endl;
    
    b = a;  // Operador de asignación
    std::cout << "\nDespués de b = a:" << std::endl;
    printArray(a, "a");
    printArray(b, "b");
    
    // Modificar a para verificar que b no cambia
    a[0] = 999;
    std::cout << "\n✏️  Modificando a[0] = 999" << std::endl;
    printArray(a, "a");
    printArray(b, "b");
    
    if (b[0] == 1)
        std::cout << "✅ Operador de asignación funcionó correctamente" << std::endl;
    else
        std::cout << "❌ ERROR: La asignación no fue profunda" << std::endl;
    std::cout << std::endl;

    // ============================================================
    // TEST 6: Auto-asignación (a = a)
    // ============================================================
    std::cout << "📌 TEST 6: Auto-asignación (a = a)" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    
    Array<int> self(3);
    self[0] = 10;
    self[1] = 20;
    self[2] = 30;
    
    std::cout << "Antes de auto-asignación: ";
    printArray(self, "self");
    
    self = self;  // Auto-asignación (no debería crashear)
    
    std::cout << "Después de self = self: ";
    printArray(self, "self");
    std::cout << "✅ Auto-asignación no causó crash" << std::endl;
    std::cout << std::endl;

    // ============================================================
    // TEST 7: Índices límite (bordes del array)
    // ============================================================
    std::cout << "📌 TEST 7: Índices límite" << std::endl;
    std::cout << "--------------------------" << std::endl;
    
    Array<int> limit(5);
    limit[0] = 100;    // Primer elemento
    limit[4] = 500;    // Último elemento
    std::cout << "Array de 5 elementos:" << std::endl;
    printArray(limit, "limit");
    std::cout << "Primero: " << limit[0] << ", Último: " << limit[4] << std::endl;
    
    // Probar índice fuera de rango
    try {
        limit[5] = 0;  // Uno más allá del límite (índice = size)
        std::cout << "❌ ERROR: limit[5] debería haber lanzado excepción" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "✅ limit[5] lanzó excepción: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // ============================================================
    // TEST 8: Objeto const (size() y operator[] const)
    // ============================================================
    std::cout << "📌 TEST 8: Objeto const (size() y operator[] const)" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    
    const Array<int> constArr(5);
    // Llenar el array const (solo se puede hacer en el constructor, no después)
    // Así que creamos uno const a partir de uno no const
    Array<int> temp(5);
    for (size_t i = 0; i < temp.size(); i++)
        temp[i] = i * 10;
    
    const Array<int> constArr2(temp);  // Copia const
    
    std::cout << "Array const - size: " << constArr2.size() << std::endl;
    std::cout << "Elementos del array const: ";
    printArray(constArr2, "constArr2");
    
    // Intentar modificar un array const (debería dar error de compilación)
    // constArr2[0] = 999;  // ❌ Esto no compilaría (descomentar para probar)
    std::cout << "✅ constArr[0] se puede leer: " << constArr2[0] << std::endl;
    std::cout << "✅ size() funciona en objeto const" << std::endl;
    std::cout << std::endl;

    // ============================================================
    // TEST 9: Array de tamaño 0
    // ============================================================
    std::cout << "📌 TEST 9: Array de tamaño 0" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    
    Array<int> zeroArr(0);
    std::cout << "Array de tamaño 0 - size: " << zeroArr.size() << std::endl;
    
    try {
        zeroArr[0] = 42;
        std::cout << "❌ ERROR: Debería haber lanzado excepción" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "✅ Excepción capturada correctamente: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // ============================================================
    // TEST 10: Asignación con diferente tamaño
    // ============================================================
    std::cout << "📌 TEST 10: Asignación con diferente tamaño" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    
    Array<int> small(2);
    small[0] = 1;
    small[1] = 2;
    
    Array<int> large(5);
    large[0] = 10;
    large[1] = 20;
    large[2] = 30;
    large[3] = 40;
    large[4] = 50;
    
    std::cout << "Antes de asignación:" << std::endl;
    printArray(small, "small (size 2)");
    printArray(large, "large (size 5)");
    
    small = large;  // Asignar un array más grande a uno más pequeño
    
    std::cout << "\nDespués de small = large:" << std::endl;
    printArray(small, "small (size 5)");
    printArray(large, "large (size 5)");
    
    if (small.size() == 5)
        std::cout << "✅ El tamaño se actualizó correctamente" << std::endl;
    else
        std::cout << "❌ ERROR: El tamaño no se actualizó" << std::endl;
    std::cout << std::endl;

    // ============================================================
    // RESUMEN FINAL
    // ============================================================
    std::cout << SEPARATOR << std::endl;
    std::cout << "✅ TODOS LOS TESTS COMPLETADOS" << std::endl;
    std::cout << SEPARATOR << std::endl;

    return 0;
}*/