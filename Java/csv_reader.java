package cas2xb3_A2_tu_rt;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class csv_reader {

	public static String[][] csv_reader_connectedCities() throws FileNotFoundException {
		// 52 routes with 2 cities as vertice for every edge, so array size 104
		String[][] connected_cities = new String[51][2];

		Scanner input = new Scanner(new File("2XB3_A2_DataSets/connectedCities.txt"));

		StringTokenizer line = new StringTokenizer(input.nextLine(), ",");

		for (int i = 0; i < 51; i++) {

			// System.out.println("Connection" + i);
			// System.out.println(line.nextToken().trim()+ line.nextToken().trim());

			connected_cities[i][0] = line.nextToken().trim();
			connected_cities[i][1] = line.nextToken().trim();

			line = new StringTokenizer(input.nextLine(), ",");
		}

		input.close();

		return connected_cities;
	}

	public static String[][] USCities() throws FileNotFoundException {
		// 52 routes with 2 cities as vertice for every edge, so array size 104
		String[][] USCities = new String[32][3];

		Scanner input = new Scanner(new File("2XB3_A2_DataSets/USCities.csv"));

		StringTokenizer line = new StringTokenizer(input.nextLine(), ",");

		for (int i = 0; i < 32; i++) {
			line = new StringTokenizer(input.nextLine(), ",");
			line.nextToken();
			line.nextToken();
			line.nextToken();
			USCities[i][0] = line.nextToken().trim();
			USCities[i][2] = line.nextToken().trim();
			USCities[i][1] = line.nextToken().trim();
		}

		input.close();

		return USCities;
	}

	public static double[][] mcdonalds() throws FileNotFoundException {
		// 52 routes with 2 cities as vertice for every edge, so array size 104
		double[][] mcdonalds = new double[13912][2];

		Scanner input = new Scanner(new File("2XB3_A2_DataSets/mcdonalds.csv"));

		StringTokenizer line = new StringTokenizer(input.nextLine(), ",");

		for (int i = 0; i < mcdonalds.length; i++) {
			line = new StringTokenizer(input.nextLine(), ",");
			mcdonalds[i][0] = Double.parseDouble(line.nextToken());
			mcdonalds[i][1] = Double.parseDouble(line.nextToken());
		}

		input.close();

		return mcdonalds;
	}

	public static double[][] burgerking() throws FileNotFoundException {
		// 52 routes with 2 cities as vertice for every edge, so array size 104
		double[][] burgerking = new double[7085][2];

		Scanner input = new Scanner(new File("2XB3_A2_DataSets/burgerking.csv"));

		StringTokenizer line = new StringTokenizer(input.nextLine(), ",");

		for (int i = 0; i < burgerking.length; i++) {
			line = new StringTokenizer(input.nextLine(), ",");
			burgerking[i][0] = Double.parseDouble(line.nextToken());
			burgerking[i][1] = Double.parseDouble(line.nextToken());
		}

		input.close();

		return burgerking;
	}

	public static double[][] wendys() throws FileNotFoundException {
		// 52 routes with 2 cities as vertice for every edge, so array size 104
		double[][] wendys = new double[5879][2];

		Scanner input = new Scanner(new File("2XB3_A2_DataSets/wendys.csv"));

		StringTokenizer line = new StringTokenizer(input.nextLine(), ",");

		for (int i = 0; i < wendys.length; i++) {
			line = new StringTokenizer(input.nextLine(), ",");
			wendys[i][0] = Double.parseDouble(line.nextToken());
			wendys[i][1] = Double.parseDouble(line.nextToken());
		}

		input.close();

		return wendys;
	}

	public static int[][] str_to_int(String[][] str_array) {

		int[][] int_array = new int[51][2];

		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 2; j++) {
				if (str_array[i][j].equals("Boston")) {
					int_array[i][j] = 0;
				} else if (str_array[i][j].equals("New York City")) {
					int_array[i][j] = 1;
				} else if (str_array[i][j].equals("Philadelphia")) {
					int_array[i][j] = 2;
				} else if (str_array[i][j].equals("Baltimore")) {
					int_array[i][j] = 3;
				} else if (str_array[i][j].equals("Washington")) {
					int_array[i][j] = 4;
				} else if (str_array[i][j].equals("Charlotte")) {
					int_array[i][j] = 5;
				} else if (str_array[i][j].equals("Atlanta")) {
					int_array[i][j] = 6;
				} else if (str_array[i][j].equals("Pittsburgh")) {
					int_array[i][j] = 7;
				} else if (str_array[i][j].equals("Columbus")) {
					int_array[i][j] = 8;
				} else if (str_array[i][j].equals("Indianapolis")) {
					int_array[i][j] = 9;
				} else if (str_array[i][j].equals("St. Louis")) {
					int_array[i][j] = 10;
				} else if (str_array[i][j].equals("Kansas City")) {
					int_array[i][j] = 11;
				} else if (str_array[i][j].equals("Denver")) {
					int_array[i][j] = 12;
				} else if (str_array[i][j].equals("Oklahoma City")) {
					int_array[i][j] = 13;
				} else if (str_array[i][j].equals("Dallas")) {
					int_array[i][j] = 14;
				} else if (str_array[i][j].equals("Houston")) {
					int_array[i][j] = 15;
				} else if (str_array[i][j].equals("New Orleans")) {
					int_array[i][j] = 16;
				} else if (str_array[i][j].equals("Memphis")) {
					int_array[i][j] = 17;
				} else if (str_array[i][j].equals("Jacksonville")) {
					int_array[i][j] = 18;
				} else if (str_array[i][j].equals("Nashville")) {
					int_array[i][j] = 19;
				} else if (str_array[i][j].equals("Chicago")) {
					int_array[i][j] = 20;
				} else if (str_array[i][j].equals("Minneapolis")) {
					int_array[i][j] = 21;
				} else if (str_array[i][j].equals("Salt Lake City")) {
					int_array[i][j] = 22;
				} else if (str_array[i][j].equals("Las Vegas")) {
					int_array[i][j] = 23;
				} else if (str_array[i][j].equals("Los Angeles")) {
					int_array[i][j] = 24;
				} else if (str_array[i][j].equals("San Francisco")) {
					int_array[i][j] = 25;
				} else if (str_array[i][j].equals("Portland")) {
					int_array[i][j] = 26;
				} else if (str_array[i][j].equals("Seattle")) {
					int_array[i][j] = 27;
				} else if (str_array[i][j].equals("Phoenix")) {
					int_array[i][j] = 28;
				} else if (str_array[i][j].equals("Albuquerque")) {
					int_array[i][j] = 29;
				} else if (str_array[i][j].equals("San Antonio")) {
					int_array[i][j] = 30;
				} else if (str_array[i][j].equals("Miami")) {
					int_array[i][j] = 31;
				}
			}
		}

		return int_array;

	}

	public static String[][] cheapest_mcD() throws FileNotFoundException {
		String[][] all_food = new String[18][2];
		String[][] cheapest = new String[2][2];

		Scanner input = new Scanner(new File("2XB3_A2_DataSets/menu.csv"));

		StringTokenizer line = new StringTokenizer(input.nextLine(), ",");

		for (int i = 0; i < 18; i++) {
			line = new StringTokenizer(input.nextLine(), "$,");
			line.nextToken();
			all_food[i][1] = line.nextToken();
			all_food[i][0] = line.nextToken();
		}

		double[] cost = new double[18];

		for (int i = 0; i < 18; i++) {
			cost[i] = Double.parseDouble(all_food[i][0]);
		}

		Arrays.sort(cost);

		for (int i = 0; i < 18; i++) {
			if (cost[0] == Double.parseDouble(all_food[i][0])) {
				cheapest[0][0] = all_food[i][1];
				cheapest[0][1] = all_food[i][0];
			}
			if (cost[1] == Double.parseDouble(all_food[i][0])) {
				cheapest[1][0] = all_food[i][1];
				cheapest[1][1] = all_food[i][0];
			}
		}

		return cheapest;
	}

	public static String[][] cheapest_burgerK() throws FileNotFoundException {
		String[][] all_food = new String[12][2];
		String[][] cheapest = new String[2][2];

		Scanner input = new Scanner(new File("2XB3_A2_DataSets/menu.csv"));

		StringTokenizer line = new StringTokenizer(input.nextLine(), ",");

		for (int i = 0; i < 18; i++) {
			line = new StringTokenizer(input.nextLine(), "$,");
		}
		
		for (int i = 0; i < 12; i++) {
			line = new StringTokenizer(input.nextLine(), "$,");
			line.nextToken();
			all_food[i][1] = line.nextToken();
			all_food[i][0] = line.nextToken();
			
		}

		double[] cost = new double[12];

		for (int i = 0; i < 12; i++) {
			cost[i] = Double.parseDouble(all_food[i][0]);
		}

		Arrays.sort(cost);

		for (int i = 0; i < 12; i++) {
			if (cost[0] == Double.parseDouble(all_food[i][0])) {
				cheapest[0][0] = all_food[i][1];
				cheapest[0][1] = all_food[i][0];
			}
			if (cost[1] == Double.parseDouble(all_food[i][0])) {
				cheapest[1][0] = all_food[i][1];
				cheapest[1][1] = all_food[i][0];
			}
		}

		return cheapest;
	}

	public static String[][] cheapest_wendys() throws FileNotFoundException {
		String[][] all_food = new String[10][2];
		String[][] cheapest = new String[2][2];

		Scanner input = new Scanner(new File("2XB3_A2_DataSets/menu.csv"));

		StringTokenizer line = new StringTokenizer(input.nextLine(), ",");

		for (int i = 0; i < 30; i++) {
			line = new StringTokenizer(input.nextLine(), "$,");
		}

		for (int i = 0; i < 10; i++) {
			line = new StringTokenizer(input.nextLine(), "$,");
			line.nextToken();
			all_food[i][1] = line.nextToken();
			all_food[i][0] = line.nextToken();
		}

		double[] cost = new double[10];

		for (int i = 0; i < 10; i++) {
			cost[i] = Double.parseDouble(all_food[i][0]);
		}

		Arrays.sort(cost);

		for (int i = 0; i < 10; i++) {
			if (cost[0] == Double.parseDouble(all_food[i][0])) {
				cheapest[0][0] = all_food[i][1];
				cheapest[0][1] = all_food[i][0];
			}
			if (cost[1] == Double.parseDouble(all_food[i][0])) {
				cheapest[1][0] = all_food[i][1];
				cheapest[1][1] = all_food[i][0];
			}
		}

		return cheapest;
	}

	public static void main(String[] args) throws FileNotFoundException {

		String[][] cheapest = cheapest_mcD();

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				System.out.print(cheapest[i][j] + " ");
			}
			System.out.println();
		}

		String[][] cheapest_BK = cheapest_burgerK();

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				System.out.print(cheapest_BK[i][j] + " ");
			}
			System.out.println();
		}

		String[][] cheapest_wendys = cheapest_wendys();

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				System.out.print(cheapest_wendys[i][j] + " ");
			}
			System.out.println();
		}
		
		  String[][] cities = csv_reader_connectedCities();
		  
		  for (int i = 0; i < 51; i++) { for (int j = 0; j < 2; j++) {
		 System.out.print(cities[i][j] + " "); } System.out.println(); }
		 
		  int[][] int_arr = str_to_int(cities);
		  
		  for (int i = 0; i < 51; i++) { for (int j = 0; j < 2; j++) {
		  System.out.print(int_arr[i][j] + " "); } System.out.println(); }
		 /* 
		 * System.out.println("USCITIES");
		 * 
		 * String[][] USCities = USCities();
		 * 
		 * for (int i = 0; i < 32; i++) { for (int j = 0; j < 3; j++) {
		 * System.out.print(USCities[i][j] + " "); } System.out.println(); }
		 */
		/*
		 * double[][] mcdonalds = burgerking(); Arrays.sort(mcdonalds, (a, b) ->
		 * Double.compare(a[0], b[0])); for (int i = 0; i < 10; i++) {
		 * System.out.println(mcdonalds[i][0] + " " + mcdonalds[i][1]); }
		 */
	}

}
