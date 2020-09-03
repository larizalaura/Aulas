

import java.util.Random;
import java.lang.Math; 

public class Individual {

	int cromossomo[]; // vetor binario
	int cromSize; //tamanho do vetor
	double fitness; //valor de aptidão


    public Individual() {} // construtor 1
	public Individual(int cromSize) { //construtor 2
		this.cromSize = cromSize;
        cromossomo = new int[cromSize];
	}
	public void createRandom() { // crio o indivio aleatoriamente

		for (int i = 0; i < cromSize; i++) {
			double range = Math.random(); // entre 0 e 1

			if(range<0.5){
				cromossomo[i] = 1;
			}else{ 
				cromossomo[i] = 0; 
			}
			 
		}
	}
	public double decode() { //decodificando de binario para numerico
		double valor = 0;
		for(int i = 0; i< cromSize; i++) {
			int position = cromSize - i;

			if ( cromossomo[i] == 1 ) {
				valor = valor + (int) Math.pow(2, position);
			}
		} 
		return valor;
	}

	public int[] getCromossomo() {
		return cromossomo;
	}
        public int getCromossomoValue(int i) {
		return cromossomo[i];
	}

	public void setCromossomo(int[] cromo) {
		for(int i=0; i<cromossomo.length; i++){
            cromossomo[i] = cromo[i];
        }
	}

	public void setCromossomoValue(int value, int position) {
		this.cromossomo[position] = value;
	}

	public double doFitness() {
		double coef = 1073741823.0; //f(x) = ax^10
		int n = 10;
		double valor = this.decode();
		//System.out.println(" decodificado "+ valor);
		fitness = Math.pow(valor/coef, n);
		return  fitness;
	}

	public int getValue(int i) {
		return cromossomo[i];
	}
        
	

	public String toString() {
		String crom = "";
		for (int i = 0; i < cromSize; i++) {
			// System.out.println("ts" + cromossomo[i]);
			crom += Integer.toString(cromossomo[i]);
			// System.out.println("crom " + Integer.toString(cromossomo[i]) + "
			// " + crom);
		}
		crom += "  " + Double.toString(fitness) + "\n";
		//System.out.println("crom " + crom);
		return crom;
	}

	public void doMutation(double mutRate) {
		
		for (int i = 0; i < cromSize; i++) {
			double range = Math.random();

			if (range < mutRate) {
				if(cromossomo[i] ==1){
					cromossomo[i] =0;
				}else{
					cromossomo[i] =1;
				}
				
			} 
		}
	}
}
