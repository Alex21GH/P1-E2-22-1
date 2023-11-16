/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegCliente.h
 * Author: Alexis
 *
 * Created on 15 de noviembre de 2023, 12:32 PM
 */

#ifndef REGCLIENTE_H
#define REGCLIENTE_H

#include "Cliente.h"
#include "Pedido.h"
#include <list>

class RegCliente {
private:
    class Cliente cliente;
    list<class Pedido> pedidos;
public:
    RegCliente();
    
    RegCliente(const RegCliente& orig);
    
    void leeCliente(ifstream &);
    void imprimeCliente(ofstream &);
    int getDNI();
    double getDescuento();
    void agregarPedido(class Pedido &pedido);
    void ordenarPedidos();
};

#endif /* REGCLIENTE_H */

