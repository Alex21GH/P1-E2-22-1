/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: Alexis
 *
 * Created on 15 de noviembre de 2023, 12:29 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;

class Pedido {
private:
    int codigo;
    double cantidad;
    int fecha;
    double subTotal;
public:
    Pedido();
    Pedido(const class Pedido& orig);
//    void operator=(const class Pedido& orig);
//    virtual ~Pedido();
    void SetSubTotal(double subTotal);
    double GetSubTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetCantidad(double cantidad);
    double GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    int leerDatos(ifstream &);
    void imprimirDatos(ofstream&);
    bool operator <(const class Pedido& orig);
};      

#endif /* PEDIDO_H */

