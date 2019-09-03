package cas2xb3_A2_tu_rt;

import java.io.FileNotFoundException;

public class Requirements {

	public static boolean[] elgible_restaurant_mcD() throws FileNotFoundException {
		//double[][] elgible_rest = new double[32][200];
		boolean[] elgible_rest = new boolean[32];

		String[][] cities = csv_reader.USCities();
		double[][] mcD = csv_reader.mcdonalds();

		for (int rest = 0; rest < mcD.length; rest++) {
			for (int c = 0; c < cities.length; c++) {
				if ((Math.abs(Double.parseDouble(cities[c][1]) - mcD[rest][0]) <= 0.5)
						&& (Math.abs(Double.parseDouble(cities[c][2]) - mcD[rest][1]) <= 0.5)) {
					elgible_rest[c] = true;

				}
			}
		}

		return elgible_rest;
	}

	public static boolean[] elgible_restaurant_burgerK() throws FileNotFoundException {
		//double[][] elgible_rest = new double[32][200];
		boolean[] elgible_rest = new boolean[32];
		
		String[][] cities = csv_reader.USCities();
		double[][] burger = csv_reader.burgerking();

		for (int rest = 0; rest < burger.length; rest++) {
			for (int c = 0; c < cities.length; c++) {
				if ((Math.abs(Double.parseDouble(cities[c][1]) - burger[rest][0]) <= 0.5)
						&& (Math.abs(Double.parseDouble(cities[c][2]) - burger[rest][1]) <= 0.5)) {
					elgible_rest[c] = true;

				}
			}
		}

		return elgible_rest;
	}

	public static boolean[] elgible_restaurant_wendy() throws FileNotFoundException {
		//double[][] elgible_rest = new double[32][200];
		boolean[] elgible_rest = new boolean[32];
		String[][] cities = csv_reader.USCities();
		double[][] wendy = csv_reader.wendys();

		for (int rest = 0; rest < wendy.length; rest++) {
			for (int c = 0; c < cities.length; c++) {
				if ((Math.abs(Double.parseDouble(cities[c][1]) - wendy[rest][0]) <= 0.5)
						&& (Math.abs(Double.parseDouble(cities[c][2]) - wendy[rest][1]) <= 0.5)) {
					elgible_rest[c] = true;

				}
			}
		}

		return elgible_rest;
	}

	public static void main(String[] args) throws FileNotFoundException {
		boolean[] restaurant = elgible_restaurant_mcD();

		for (int i = 0; i < 32; i++) {
			
				System.out.println(restaurant[i]);
			
		}
	}

}
