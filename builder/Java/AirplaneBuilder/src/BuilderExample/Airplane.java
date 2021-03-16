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
/** "Product" */
public class Airplane {

	private String type;
	private float wingspan;
	private String powerplant;
	private int crewSeats;
	private int passengerSeats;
	private String avionics;
	private String customer;

	Airplane (String customer, String type){
		this.customer = customer;
		this.type = type;
        }
	public void setWingspan(float wingspan) {
		this.wingspan = wingspan;
        }

	public void setPowerplant(String powerplant) {
		this.powerplant = powerplant;
        }
	public void setAvionics(String avionics) {
		this.avionics = avionics;
        }
	public void setNumberSeats(int crewSeats, int passengerSeats) {
		this.crewSeats = crewSeats;
		this.passengerSeats = passengerSeats;
        }
	public String getCustomer() {
		return customer;
        }
	public String getType() {
		return type;
        }
}

