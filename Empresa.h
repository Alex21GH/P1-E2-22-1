/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Empresa.h
 * Author: Alexis
 *
 * Created on 15 de noviembre de 2023, 12:35 PM
 */

#ifndef EMPRESA_H
#define EMPRESA_H

#include "Producto.h"
#include "RegCliente.h"

class Empresa {
private:
    list<class Producto>lstProductos;
    list<class RegCliente>lstClientes;
    
    void println(ofstream arch, char c);
    list<Producto>::iterator buscarProducto(class Producto producto);
    list<RegCliente>::iterator buscarCliente(int );
public:
    void leerClientes(const char*);
    void imprimirClientes(const char*);
    void leerPedidos(const char*);
    void ordenarPedidos();
    void imprimirProductos(const char*);
};

#endif /* EMPRESA_H */

