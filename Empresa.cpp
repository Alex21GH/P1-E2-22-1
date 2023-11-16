/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Empresa.cpp
 * Author: Alexis
 * 
 * Created on 15 de noviembre de 2023, 12:35 PM
 */

#define MAX_CAR_LINE 100
#include "Empresa.h"

void Empresa::leerClientes(const char*archnomb){
    ifstream arch(archnomb,ios::in);
    if(!arch){
        cout<<"ERROR: No se pudo abrir el archivo "<<archnomb<<endl;
        exit(1);
    }
    
    RegCliente regcli;
    while(true){
        regcli.leeCliente(arch);
        if(arch.eof()) break;
        lstClientes.push_back(regcli);
    }
}

void Empresa::imprimirClientes(const char*archnomb){
    ofstream arch(archnomb,ios::out);
    if(!arch){
        cout<<"ERROR: No se pudo abrir el archivo "<<archnomb<<endl;
        exit(1);
    }
    
    arch<<right<<setw(50)<<"CLIENTES"<<endl;
    
    for(RegCliente regcli : lstClientes){
        regcli.imprimeCliente(arch);
    }
}

void Empresa::leerPedidos(const char*archnomb){
    ifstream arch(archnomb,ios::in);
    if(!arch){
        cout<<"ERROR: No se pudo abrir el archivo "<<archnomb<<endl;
        exit(1);
    }
    
    
    class Producto producto;
    list<class Producto>::iterator itprod;
    class Pedido pedido;    
    int dnicli; double subtotal;
    list<class RegCliente>::iterator itregcli;
    
    while(true){
        // Leyendo y agregando producto
        producto.leerDatos(arch);
        if(arch.eof()) break;
        itprod = buscarProducto(producto);
        if(itprod == lstProductos.end()){
            lstProductos.push_back(producto);
        }
        // Leyendo y agregando pedido a registro cliente
        dnicli = pedido.leerDatos(arch);
        itregcli = buscarCliente(dnicli);
        if(itregcli != lstClientes.end()){
            // Completar pedido
            pedido.SetCodigo(producto.GetCodigo());
            subtotal = pedido.GetCantidad()*producto.GetPrecioUnitario()*
                    (1.00-producto.GetDescuento()/100)*
                    (1.00- (*itregcli).getDescuento()/100);
            pedido.SetSubTotal(subtotal);
            // Asignarlo a cliente
            (*itregcli).agregarPedido(pedido);
        }
        
    }
}

list<Producto>::iterator Empresa::buscarProducto(class Producto producto){
    list<Producto>::iterator it;
    for(it=lstProductos.begin(); it!=lstProductos.end(); it++)
        if((*it).GetCodigo() == producto.GetCodigo()) return it;
    return lstProductos.end();
}

list<RegCliente>::iterator Empresa::buscarCliente(int dni){
    list<RegCliente>::iterator it;
    for(it=lstClientes.begin(); it!=lstClientes.end(); it++)
        if((*it).getDNI() == dni) return it;
    return lstClientes.end();
}

void Empresa::ordenarPedidos(){
    list<RegCliente>::iterator it;
    for(it=lstClientes.begin(); it!=lstClientes.end(); it++)
        (*it).ordenarPedidos();
}

void Empresa::imprimirProductos(const char*archnomb){
    ofstream arch(archnomb,ios::out);
    if(!arch){
        cout<<"ERROR: No se pudo abrir el archivo "<<archnomb<<endl;
        exit(1);
    }
    
    arch<<right<<setw(50)<<"PRODUCTOS"<<endl;
    
    for(Producto producto : lstProductos){
        producto.imprimirDatos(arch);
    }
}

void Empresa::println(ofstream arch, char c){
    arch<<setfill(c)<<setw(MAX_CAR_LINE)<<' '<<setfill(' ')<<endl;
}