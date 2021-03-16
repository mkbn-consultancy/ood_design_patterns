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

/** "AbstractBuilder" */
public abstract class AirplaneBuilder{
	protected Airplane airplane;
	protected String customer;
	protected String type;

	public Airplane getAirplane() {
		return airplane;
        }
	public void createNewAirplane() {
		airplane = new Airplane(customer, type);
        }
	public abstract void buildWings();
	public abstract void buildPowerplant();
	public abstract void buildAvionics();
	public abstract void buildSeats();
}
