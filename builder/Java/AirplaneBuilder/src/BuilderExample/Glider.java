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
public class Glider extends AirplaneBuilder {
	Glider (String customer){
		super.customer = customer;
		super.type = "Glider v9.0";
	}
	public void buildWings() {
		airplane.setWingspan(57.1f);
	}
	public void buildPowerplant() {}

	public void buildAvionics() {}

	public void buildSeats() {
		airplane.setNumberSeats(1,0);
		
	}
}
