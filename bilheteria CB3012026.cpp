#include <iostream>
#include <stdlib.h>
#include <iomanip>
#define LIN 15
#define COL 40

using namespace std;

int main()
{
 /* Objetivo de fazer a bilheria de um teatro com 600 lugares, com 15 fileiras e 40 poltronas   i = linha   j=coluna*/

  int i;
  int j;

 /* Variaveis que aguardam interação do usuario para escolher a poltrona */ 
  int escolher;

  int poltrona;
  int fileira;

  int lugares_escolhidos = 0;
  float faturamento = 0;

  
	 /* Aqui tem uma matriz de booleanos para poltronas, os lugurares escolhidos são false e os disponíveis são true! */
	  bool poltronas[LIN][COL];

	 /*[POSIÇÕES DAS POLTRONAS */

	  for (i = 0; i < LIN; ++i)
	  {
	    for (j = 0; j < COL; ++j)
	    {
	      poltronas[i][j] = true;
	    }
	  }

		  do
		  {
		    cout << "0. Finalizar" << endl;
		    cout << "1. Reservar poltrona" << endl;
		    cout << "2. Mapa de ocupação" << endl;
		    cout << "3. Faturamento" << endl;

		    cin >> escolher;

			    /*[RESERVAR POLTRONAS]*/

			    if (escolher == 1)
			    {
			      cout << endl
				   << "A organizacao das poltronas se dá por: 15 fileiras e cada fileira tem 40 poltronas." << endl;

			      cout <<  "Selecione o numero da fileira que deseja escolher (max 15): ";
			      cin >> fileira;

			      cout << "Selecionar o numero da poltrona (Max 40): ";
			      cin >> poltrona;

			      --poltrona;
			      --fileira;

			      if (poltronas[fileira][poltrona])
			      {
				poltronas[fileira][poltrona] = false;

				if (fileira >= 1 && fileira <= 5)
				{
				  faturamento += 50;
				}
				else if (fileira >= 6 && fileira <= 10)
				{
				  faturamento += 30;
				}
				else if (fileira >= 11 && fileira <= 15)
				{
				  faturamento += 15;
				}

				lugares_escolhidos++;

				cout << endl
				     << "Muito bem! sua reserva foi realizada. Caso queira continuar pode escolher outra poltrona." << endl;
			      }
			      else
			      {
				cout << endl
				     << "Oops!! Não foi possível efetuar sua reserva, esta poltrona já foi escolhida. Por favor, faça outra escolher." << endl;
			      }
			    }

				   /*[TELA DE RESERVAS]
					 onde . é usado para os lugares que estão disponíveis e # para os que foram escolhidos! */
				    else if (escolher == 2)
				    {
				      for (i = 0; i < LIN; ++i)
				      {
					for (j = 0; j < COL; ++j)
					{
					  if (poltronas[i][j])
					    cout << ".";
					  else
					    cout << "#";
					  cout << " | ";
					}
					cout << endl;
				      }
				    }

					  /* TELA DE FATURAMENTO */
					    else if (escolher == 3)
					    {
					      cout << endl
						   << "Faturamento e Ocupação das poltronas : " << endl;

					      cout << endl
						   << "numero de poltronas ocupadas: " << lugares_escolhidos;
					      cout << endl
						   << "Faturamento total: R$ " << setprecision(2) << fixed << faturamento << endl;
					    }

					  } while (escolher != 0);

					  return 0;
					}