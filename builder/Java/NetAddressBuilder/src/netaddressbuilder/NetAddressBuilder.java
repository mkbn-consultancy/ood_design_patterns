/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package netaddressbuilder;

/**
 *
 * @author Miri
 */
public class NetAddressBuilder {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Address address = Address.startBuild().url("www.google.com").port(80).build();
        System.out.println(address.toString());
        address = Address.startBuild().url("www.google.com").port(80).protocol("TCP").build();
        System.out.println(address.toString());
    }
    
}
