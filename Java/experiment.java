package cas2xb3_A2_tu_rt;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.StringTokenizer;

public class experiment {

	public static void main(String[] args) throws IOException {
		Digraph city = new Digraph(32);

		String[][] str_arr = csv_reader.csv_reader_connectedCities();
		int[][] int_arr = csv_reader.str_to_int(str_arr);

		for (int i = 0; i < int_arr.length; i++) {
			city.addEdge(int_arr[i][0], int_arr[i][1]);
		}
		System.out.println(city.toString());

		DepthFirstDirectedPaths city_dfs = new DepthFirstDirectedPaths(city, 0);
		System.out.println();
		System.out.println("DFS: " + city_dfs.pathTo(21));

		BreadthFirstDirectedPaths city_bfs = new BreadthFirstDirectedPaths(city, 0);
		System.out.println();
		System.out.println("BFS: " + city_bfs.pathTo(21));

		
		File file = new File("2XB3_A2_DataSets\\a2_out.txt");

		// creates the file
		file.createNewFile();

		// creates a FileWriter Object
		FileWriter writer = new FileWriter(file);
		

		// Writes the content to the file
		writer.write("DFS: " + city_dfs.pathTo(21) + "\n" + "BFS: " + city_bfs.pathTo(21));
		writer.flush();
		writer.close();

		Scanner input = new Scanner(new File("2XB3_A2_DataSets/a2_out.txt"));

		StringTokenizer line = new StringTokenizer(input.nextLine(), " ");
		
		line.nextToken();
		
		
		String[][] USCities = csv_reader.USCities();
		String[] tokens = new String[line.countTokens()];
		String[] cities = new String[line.countTokens()];
		int count = 0;
		while (line.hasMoreTokens()) {
			tokens[count] = line.nextToken();
			count++;
		}
		
		for (int i = 0; i < tokens.length; i++) {
			int x = Integer.parseInt(tokens[i]);
			cities[i] = USCities[x][0];
		}
		
		line = new StringTokenizer(input.nextLine(), " ");
		line.nextToken();
		String[] tokens1 = new String[line.countTokens()];
		String[] cities1= new String[line.countTokens()];
		int count1 = 0;
		while (line.hasMoreTokens()) {
			tokens1[count1] = line.nextToken();
			count1++;
		}
		
		for (int i = 0; i < tokens1.length; i++) {
			int x = Integer.parseInt(tokens1[i]);
			cities1[i] = USCities[x][0];
		}
		
		input.close();
		
		File file1 = new File("2XB3_A2_DataSets\\a2_out.txt");

		// creates the file
		file.createNewFile();

		// creates a FileWriter Object
		FileWriter writer1 = new FileWriter(file1);
		
		writer1.write("DFS: ");
		for (int i = 0; i < cities.length; i++) {
			writer1.write(cities[i] + ", ");
		}
		writer1.write("\n");
		
		writer1.write("BFS: ");
		for (int i = 0; i < cities1.length; i++) {
			writer1.write(cities1[i] + ", ");
		}
		writer1.write("\n");

		// Writes the content to the file
		//writer1.write("DFS: " + city_dfs.pathTo(21) + "\n" + "BFS: " + city_bfs.pathTo(21));
		writer1.flush();
		writer1.close();
		
		//////////////////
		
		String[][] connec_cities = csv_reader.csv_reader_connectedCities();
		int[][] Int_arr = csv_reader.str_to_int(connec_cities);
		
		File file2 = new File("2XB3_A2_DataSets\\a2_input.txt");

		// creates the file
		file.createNewFile();

		// creates a FileWriter Object
		FileWriter writer2 = new FileWriter(file2);
		
		writer2.write(city.V() + "\n" + city.E() + "\n");
		
		boolean[] mcD = Requirements.elgible_restaurant_mcD();
		boolean[] BK = Requirements.elgible_restaurant_burgerK();
		boolean[] wendy = Requirements.elgible_restaurant_wendy();
		String[][] mcD_food = csv_reader.cheapest_mcD();
		String[][] BK_food = csv_reader.cheapest_burgerK();
		String[][] wendy_food = csv_reader.cheapest_wendys();
		
		for (int i = 0; i < 51; i++) {
			writer2.write(Int_arr[i][0] + " " + Int_arr[i][1] + " ");
			if (mcD[Int_arr[i][1]]) {
				if (i%2 == 0) {
					writer2.write(mcD_food[0][1] + "\n");
				}
				else {
					writer2.write(mcD_food[1][1] + "\n");
				}
			}
			else if (BK[Int_arr[i][1]]) {
				if (i%2 == 0) {
					writer2.write(BK_food[0][1] + "\n");
				}
				else {
					writer2.write(BK_food[1][1] + "\n");
				}
			}
			else if (wendy[Int_arr[i][1]]) {
				if (i%2 == 0) {
					writer2.write(wendy_food[0][1] + "\n");
				}
				else {
					writer2.write(wendy_food[1][1] + "\n");
				}
			}
		}
		
		

		// Writes the content to the file
		//writer1.write("DFS: " + city_dfs.pathTo(21) + "\n" + "BFS: " + city_bfs.pathTo(21));
		writer2.flush();
		writer2.close();
		
		
		
		In in = new In("2XB3_A2_DataSets\\a2_input.txt");
        EdgeWeightedDigraph G = new EdgeWeightedDigraph(in);
        int s = 0;

        // compute shortest paths
        DijkstraSP sp = new DijkstraSP(G, s);


        // print shortest path
        for (int t = 0; t < G.V(); t++) {
            if (sp.hasPathTo(t)) {
                StdOut.printf("%d to %d (%.2f)  ", s, t, sp.distTo(t));
                for (DirectedEdge e : sp.pathTo(t)) {
                    StdOut.print(e + "   ");
                }
                StdOut.println();
            }
            else {
                StdOut.printf("%d to %d         no path\n", s, t);
            }
        }
		
	}

}
