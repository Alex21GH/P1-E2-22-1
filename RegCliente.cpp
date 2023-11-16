/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegCliente.cpp
 * Author: Alexis
 * 
 * Created on 15 de noviembre de 2023, 12:32 PM
 */

#include "RegCliente.h"

RegCliente::RegCliente() {    
}

RegCliente::RegCliente(const RegCliente& orig) {
    cliente = orig.cliente;
    pedidos = orig.pedidos;
}

void RegCliente::leeCliente(ifstream &arch){
    cliente.leerDatos(arch);
    if(arch.eof()) return;
    double desc = 0;
    switch(cliente.GetTipo()){
        case 'A':
            desc = 23.5; break;
        case 'B':
            desc = 16.8; break;
        case 'C':
            desc = 8.3; break;            
    }
    cliente.SetDescuento(desc);
}



void RegCliente::imprimeCliente(ofstream &arch){
    
    
    cliente.imprimirDatos(arch);
    arch<<"Pedidos: "<<endl;
    list<Pedido>::iterator it;
//    cout<<endl<<"Cliente: "<<cliente.GetDni()<<"   cant pedidos: "<<pedidos.size()<<endl;
    for(it=pedidos.begin(); it!=pedidos.end(); it++){
        (*it).imprimirDatos(arch);
    }
    arch<<endl;
}

int RegCliente::getDNI(){
    return cliente.GetDni();
}

double RegCliente::getDescuento(){
    return cliente.GetDescuento();
}

void RegCliente::agregarPedido(class Pedido &pedido){
    
    pedidos.push_back(pedido);
//    cout<<"Cliente: "<<cliente.GetDni()<<"   cant pedidos: "<<pedidos.size()<<endl;
}

void RegCliente::ordenarPedidos(){
    pedidos.sort();
}