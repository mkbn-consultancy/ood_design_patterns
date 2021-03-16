/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package BuilderExample;

/**
 *
 * @author Miri
 */
/** "ConcreteBuilder" */
public class CropDuster extends AirplaneBuilder {

	CropDuster(String customer){
		super.customer = customer;
		super.type = "Crop Duster v3.4";
        }
	public void buildWings() {
		airplane.setWingspan(9f);
        }
	public void buildPowerplant() {
		airplane.setPowerplant("single piston");
        }
	public void buildAvionics() {}
	public void buildSeats() {
		airplane.setNumberSeats(1,1);
        }
}

