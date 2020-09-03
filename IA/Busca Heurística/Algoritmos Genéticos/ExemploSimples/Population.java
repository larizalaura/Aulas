import java.lang.Math; 


public class Population {
	Individual pop[]; // um conjunto de individuos
	double fitPop[]; // array para armazenar os fitness
	int tamPop;

	public Population() {
	}

	public Population(int tamPop, int cromSize) {
            this.tamPop = tamPop;
            pop = new Individual[tamPop];
            fitPop = new double[tamPop];
            for (int i = 0; i < tamPop; i++) {
                    pop[i] = new Individual(cromSize);
            }
	}

   
	public void doFitness() {
		for (int i = 0; i < tamPop; i++) {
			fitPop[i] = pop[i].doFitness();
			//System.out.println("fitness de cada individuo " + fitPop[i]);
		}
	}
	public void estatistica(){
		int position = getBest();
		Individual best = this.get(position);
		int soma=0;
		int[] crom = best.getCromossomo();
		for(int i=0;i<best.cromSize;i++){
			soma+= crom[i];
		}
		System.out.println(" Media: "+ getMedia() + " Best: " + fitPop[getBest()] +  "   "+ best.toString() + "\n");
	}
	
	public double getMedia(){
		double media = 0;
		for (int i = 0; i < tamPop; i++) {
			media +=fitPop[i];
		}
		media = media/tamPop;
		return media;
	}
	// operador de seleção
	public Individual torneio(double torRate) {

		int number = (int) (torRate * tamPop); // 3% de 100 daria 3
		int t1 = (int) (Math.random() * tamPop);
		int winner = t1;
               
		for (int i = 1; i < number; i++) {
			int t2 = (int) (Math.random() * tamPop);
			if (fitPop[t2] > fitPop[winner]) {
				winner = t2;
			}
		}
           
		return pop[winner];
	}

	public void createRandomPop() {

		for (int i = 0; i < tamPop; i++) {
			pop[i].createRandom();
		}
	}

	public int getBest() {
		double bestFit = fitPop[0];
		int best = 0;

		for (int i = 1; i < tamPop; i++) {
			if (fitPop[i] > bestFit) {
				bestFit = fitPop[i];
				best = i;
			}
		}
		return best;
	}

	public int getSecBest(int posBest) {
		int best2;
		double fitBest2;
		if (posBest != 0) {
			best2 = 0;
			fitBest2 = fitPop[0];
		} else {
			fitBest2 = fitPop[1];
			best2 = 1;
		}
		for (int i = 0; i < tamPop; i++) {
			if (fitPop[i] > fitBest2) {
				if (posBest != i) {
					fitBest2 = fitPop[i];
					best2 = i;
				}
			}
		}
		return best2;
	}

	public void setIndividual(int i, Individual best1) {
            pop[i].setCromossomo(best1.getCromossomo());

	}

	public void setPop(Population nextPop) {
            for(int i=0;i<pop.length; i++){
                pop[i].setCromossomo(nextPop.get(i).getCromossomo());
            }
        
        }

	public Individual get(int best) {
		return pop[best];
	}
	
	public String toString(){
		String popst = "";
		for (int i = 0; i < tamPop; i++) {
			popst += pop[i].toString(); 
		}
		return popst;
	}

}
