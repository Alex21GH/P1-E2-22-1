/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alexis
 *
 * Created on 15 de noviembre de 2023, 12:28 PM
 */

#include "Empresa.h"

int main(int argc, char** argv) {
    
    class Empresa empresa;
    empresa.leerClientes("Clientes.csv");
//    empresa.imprimirClientes("PruebaClientes.txt");
    empresa.leerPedidos("Pedidos.csv");
    empresa.ordenarPedidos();
    empresa.imprimirProductos("ReporteDeProductos.txt");
    empresa.imprimirClientes("ReporteDeClientes.txt");

    return 0;
}

