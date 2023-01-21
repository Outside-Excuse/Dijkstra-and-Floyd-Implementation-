//Alejandro Hidalgo Badillo 
//Actividad 3.2 Implementacion de Dijkstra and Floyd
#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <tuple>
#include <vector>

using namespace std;
const int INF = 1e9; // se utiliza solamente en floyd
const int Infinity = 9999; // se utiliza solamente en dikstra

//se declara el algoritmo de floyd 
void Floyd(std::vector<std::vector<int>> dist,int n){
	//la dificultad de FLoyd es de tipo cubica osea es: O(n x n x n) debido a que tiene 3 bucles anidados de tipo for para poder realizar su comparacion
	for (int i = 0; i<n;i++){
		for (int j = 0; j<n;j++){
			for(int k = 0; k<n;k++){
				if(dist[j][i] + dist[i][k] < dist[j][k]){
					dist[j][k] = dist[j][i] + dist[i][k]; //se hace la respectiva comparacion de sumatoria de valores y si se cumple igualamos la direccion del la arista
				} // fin del if
			}// fin del tercer for
		} //fin del segundo for
	} // fin del primer for

	for (int i = 0; i<n;i++){
		for (int j = 0; j<n;j++){
			if(dist[i][j]==INF){
				cout<<"INF "; // si no tuvo manera de comunicarse por cierto nodo imprimimos un valor muy alto
			}
			else{
				cout<<dist[i][j]<<" ";		//imprimimos el arreglo correspondiente a los resultados obtenidos
			}
			
		}
		cout<<endl;
	} //fin de la funcion de floyd

}
void dijkstra(std::vector<std::vector<int>> G, long unsigned size, int source) {

  // se definen los pares a utilizar
  typedef std::pair<int, int> P;
  // Crear conjunto de vertices Q
  std::priority_queue<P, std::vector<P>, std::greater<P>> Q;

  // distancia desconocida al vertice 
  std::vector<unsigned int> distance(size, Infinity);
  // predecesor del vertice
  std::vector<int> previous(size, -1);

  // se inicializa
  distance[source] = 0;

  //se almacenan los valores en nuestra matriz de vectores Q
  for (int v = 0; v < size; v++) {
    Q.push(std::make_pair(v, distance[v]));
  }
  
  // el siguiente while contiene el ciclo principal de Dikstra
  while (!Q.empty()) { //realizara este bucle hasta que nuestro vector de vectores de tipo entero este vacio
   
    auto u = Q.top().first;
    Q.pop();
    // printf("u: %d, v: %d\n", u, std::get<1>(p));
    for (int v = 0; v < size; v++) {
      // si un nodo adyacente existe
      if (G[u][v] > 0) {
        int alt = distance[u] + G[u][v];
        if (alt < distance[v]) {
          distance[v] = alt;
          previous[v] = u;
          Q.push(std::make_pair(v, distance[v]));
        } //fin de if
      }//fin del if
    } // fin de for
  } //fin del while
	//con este print solo puedes vizualisar maximo una matriz de 26 x 26, se puede modificar para expandir la vizualizacion.
  int letters[26] = {
    1, 2, 3, 4, 5, 6, 7, 8,
    9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26
  };
  //realizamos la impresion de nuestros resultados con la sintaxis pedida en el problema.
  for (int i = 0; i < size; i++) {
    if (distance[i] == Infinity || distance[i] == 0) {
			continue;
    } else {
      printf("node %i to node %i : %d\n", letters[source], letters[i], distance[i]); // hacemos el print correspondiente
    } //fin del else
  } // fin de ciclo for
} // final del algoritmo de dikstra

//la complejidad del algoritmo de disktra es O(n x n) debido a que tiene un while con un ciclo for anidado.



//inicio del main
int main() {
  vector <vector<int> > data; //matriz de vectores
	vector<vector<int> > floydData;
	vector<string> texto; //almacenar la linea de la matriz
	
  string linea;
	//cout<<"introduce n"<<endl;

  int n,cont, cont2;
	cin >> n; //introducir n
	//guardar matriz
  getline(cin, linea);
	int arr[n][n];
	int arreglo[n];
  while (getline(cin, linea)) {
    texto.push_back(linea);
  }//guardar matriz



	//cout<<"<--------->"<<endl;
	//creamos dos matrizes, una vector y otra normal
	/*
--------------------------------------------------------
	ciclos anidados para guardar los valores version dos (util)
--------------------------------------------------------
*/

	for(int i = 0; i<n;i++){
		data.push_back(vector<int>());
		floydData.push_back(vector<int>());
		cont = 0;
		
		for(int b = 0; b<n; b++){
			cont2 = 0;
			if(texto[i][cont] == '-'){
				//graf[i].push_back(stoi(texto[i].substr(cont,cont2)));
				data[i].push_back(0);
				floydData[i].push_back(INF);
				cont = cont+3;
			}
			else{
				if (texto[i][cont+1] != ' '){
					cont2++;
					while(texto[i][cont+cont2] != ' '){
						cont2++;
					}
					data[i].push_back(stoi(texto[i].substr(cont,cont2)));
					floydData[i].push_back(stoi(texto[i].substr(cont,cont2)));
					cont = cont+cont2+1;
				}
				else{
					data[i].push_back(texto[i][cont]-'0');
					floydData[i].push_back(texto[i][cont]-'0');
					cont = cont+2;
				}
			
				
				
			}
			
		} //fin del segundo for
	} //fin del primer for




	/*
--------------------------------------------------------
	ciclos anidados para guardar los valores version uno
--------------------------------------------------------

	for(int a=0;a<n;a++){
		data.push_back(vector<int>());
		string Number;
		int contSpace = 0;
		floydData.push_back(vector<int>());
		for (int b=0;b<n;b++){
			
			
			if(texto[a][contSpace]=='-'){//condicional para ver si el numero es negativo
				arr[a][b]=-1;
				data[a].push_back(0);
				floydData[a].push_back(INF);
				
				contSpace = contSpace+3;
				//cout<<data[a][b]<<" "; 
			}

			else{
				
				if(texto[a][contSpace+1] != ' ' && contSpace<(texto[a].size()-1)){
					int temp;
					if (b==0){
						temp = 0;
					}
					else{
						temp = contSpace;
					} 
					if (b==0){
								contSpace=contSpace+2;
					}
							else{
								while(texto[a][contSpace+1] != ' '){
									contSpace++;
								}
									}
					
								
//ahora la complejidad del codigo del main tambien es O(n x n x n) debido a que tiene anidado un while dentro de un for que esta dentro de otro for 
					
							
						
					Number = texto[a].substr(temp,contSpace);
					//cout<< "Number"<<Number<<endl;
					if (stoi(Number) == -1 ){
						arr[a][b]=-1;
						data[a].push_back(0);
						floydData[a].push_back(INF);
					}
					else{
					arr[a][b]= stoi(Number);
					data[a].push_back(stoi(Number));
					
					floydData[a].push_back(stoi(Number));
					contSpace++;
					}
				
			}
				else{
					
					arr[a][b]= texto[a][contSpace]-'0';
					data[a].push_back(texto[a][contSpace]-'0');
					floydData[a].push_back(texto[a][contSpace]-'0');
					contSpace = contSpace+2;
				}
			//se guardan los datos de entrada que sean mayores a -1
			//cout<<data[a][b]<<" "; 
			}
		} //fin del segundo for

		//cout<<endl;
	} //fin del primer for
	//for (int i = 0; i<n;i++){
	//	for(int j = 0; j<n;j++){
	//		cout<<data[i][j]<<" ";
	//	}
	//	cout<<endl;
	//}
*/
	//data[n-1][n-1]=0;
	//floydData[n-1][n-1]=0;
//cout<<"array: "<<endl;
	//	for (int i = 0; i<n;i++){
	//	for(int j = 0; j<n;j++){
	//		cout<<floydData[i][j]<<" ";
	//	}
	//	cout<<endl;
	//}

	//se llama a la funcion de Disktra
		cout<<"Dijkstra:"<<endl;
	  for (int source = 0; source < data.size(); source++) 	{
    dijkstra(data, data.size(), source);
  }
	//se llama a la funcion de floyd
	cout<<endl<<"Floyd:"<<endl;
	vector<vector<int>> dist = floydData;
	Floyd(dist,n); // se llama a la funcion de floyd
}

//la complejidad general del codigo es O(n x n x n) gracias al algoritmo de floyd que tiene 3 ciclos de for anidados y tambien el main que tiene esa misma complejidad por los metodos de asignacion de variables