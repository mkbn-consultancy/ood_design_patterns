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

/** Application in which given types of airplanes are being constructed. */
public class BuilderExample {
	public static void main(String[] args) {
		// instantiate the director (hire the engineer)
		AerospaceEngineer aero = new AerospaceEngineer();
		
		// instantiate each concrete builder (take orders)
		AirplaneBuilder crop = new CropDuster("Farmer Joe");
		AirplaneBuilder fighter = new FighterJet("The Navy");
		AirplaneBuilder glider = new Glider("Tim Rice");
		
		// build a CropDuster
		aero.setAirplaneBuilder(crop);
		aero.constructAirplane();
		Airplane completedCropDuster = aero.getAirplane();
		System.out.println(completedCropDuster.getType() +
				" is completed and ready for delivery to " +
				completedCropDuster.getCustomer());

		// the other 2 builds removed to fit the code on one slide
	}
}
