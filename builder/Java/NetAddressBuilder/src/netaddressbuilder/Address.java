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
public class Address {
    private final String protocol;
    private final String url;
    private final int port;
    private final String path;
    private final String description;
    // only builder should be able to create an instance
    private Address(Builder builder) {
        this.protocol = builder.protocol;
        this.url = builder.url;
        this.port = builder.port;
        this.path = builder.path;
        this.description = builder.description;
    }
 
    @Override
    public String toString(){
        String addrStr = "protocol="+this.protocol;
        addrStr+="\n";
        addrStr+=("url="+this.url);
        addrStr+="\n";
        addrStr+=("port="+this.port);
        addrStr+="\n";
        addrStr+=("path="+this.path);
        addrStr+="\n";
        addrStr+=("description="+this.description);
        addrStr+="\n";
        return addrStr;
    }
    
    interface Url {
        public Port url(String url);	//the  Url interface returns a Port
    }

    interface Port {
        public Build port(int port);	//the Port interface returns a Build
    }

    interface Build {	//The Build interface allows set the other data
        public Build protocol(String protocol);
        public Build path(String path);
        public Build description(String description);
        public Address build();
    }

    public static Url startBuild() {
        return new Builder();    //returns a builder as a Url. An Address’ method
    }

    private static class Builder implements Url, Port, Build{
        private String protocol;
        private String url;
        private int port;
        private String path;
        private String description;

        /** Mandatory, must be followed by {@link Port#port(int)}  */
        @Override
        public Port url(String url) {
        this.url = url;
            return this;	//returns a builder as a Port
        }

        /** Mandatory, must be followed by methods in {@link Build}  */
        @Override
        public Build port(int port) {
            this.port = port;
            return this;	//returns a builder as a Build
        }
        /** Non-mandatory, must be followed by methods in {@link Build}  */
        @Override
        public Build protocol(String protocol) {
            this.protocol = protocol;
            return this;	//returns the build interface
        }
        /** Non-mandatory, must be followed by methods in {@link Build}  */
        @Override
        public Build path(String path) {
            this.path = path;
            return this;	 //returns the build interface
        }
        /** Non-mandatory, must be followed by methods in {@link Build}  */
        @Override
        public Build description(String description) {
            this.description = description;
            return this;	 //returns the build interface
        }

        /** Creates an instance of {@link Address} */
        @Override
        public Address build() {
            return new Address(this);   //creates a new Address with a builder.
        }

    }
}


    