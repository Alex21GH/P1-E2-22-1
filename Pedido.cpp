/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: Alexis
 * 
 * Created on 15 de noviembre de 2023, 12:29 PM
 */

#include "Pedido.h"

Pedido::Pedido() {
    subTotal = 0;
    codigo = 0;
}

Pedido::Pedido(const class Pedido& orig) {
    (*this) = orig;
}

//void Pedido::operator=(const class Pedido& orig){
//    codigo = orig.codigo;
//    cantidad = orig.cantidad;
//    fecha = orig.fecha;
//    subTotal = orig.subTotal;
//}

//Pedido::~Pedido() {
//}

void Pedido::SetSubTotal(double subTotal) {
    this->subTotal = subTotal;
}

double Pedido::GetSubTotal() const {
    return subTotal;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetCantidad(double cantidad) {
    this->cantidad = cantidad;
}

double Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

int Pedido::leerDatos(ifstream &arch){
    /*
     int codigo;
    double cantidad;
    int fecha;
    double subTotal;*/
    int dnicli,dd,mm,aa; char c;
    arch>>cantidad>>c>>dnicli>>c>>dd>>c>>mm>>c>>aa;
    fecha = aa*10000 + mm*100 + dd;
    return dnicli;
}

void Pedido::imprimirDatos(ofstream&arch){
    arch<<setprecision(2)<<fixed;
    arch<<left<<setw(10)<<codigo<<right<<setw(6)<<cantidad<<
            setw(15)<<fecha<<setw(10)<<subTotal<<endl;
}

bool Pedido::operator <(const class Pedido& orig){
    return fecha < orig.fecha;
}