
/**
 *
 * @author Lariza Laura de Oliveira
 *    02 de Agosto de 2020
 */
public class Main {
	
    public static void main(String[] args) throws Exception{
	
		int generation =5000;
		double crossrate = 0.6;
		double mutacao = 0.03;
		double torrate= 0.06;
		int tampop = 50;
		int cromSize = 30;
		
		
		Generation g = new Generation(generation, crossrate, mutacao, torrate,tampop,cromSize );
		g.doGeneration();
		
	}
    
}
