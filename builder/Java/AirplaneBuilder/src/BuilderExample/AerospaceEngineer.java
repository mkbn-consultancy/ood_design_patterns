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

/** "Director" */
public class AerospaceEngineer {
	private AirplaneBuilder airplaneBuilder;

	public void setAirplaneBuilder(AirplaneBuilder ab) {
		airplaneBuilder = ab;
        }
	public Airplane getAirplane() {
		return airplaneBuilder.getAirplane();
        }
	public void constructAirplane() {
		airplaneBuilder.createNewAirplane();
		airplaneBuilder.buildWings();
		airplaneBuilder.buildPowerplant();
		airplaneBuilder.buildAvionics();
		airplaneBuilder.buildSeats();
        }
}

