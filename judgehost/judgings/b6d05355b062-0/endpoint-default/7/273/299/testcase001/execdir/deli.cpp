#include<iostream>
#include<string.h>
using namespace std;
int main(){
		int L, N;
			bool hasPrinted;
				char irregular[20][2][20], words[20];
					cin >> L >> N;
						for(int i = 0; i < L; i++){
									cin >> irregular[i][0] >> irregular[i][1];
										}
							for(int i = 0; i < N; i++){
										cin >> words;
												hasPrinted = false;
														for(int j = 0; j < L; j++){
																		if (!strcmp(words, irregular[j][0])){
																							cout << irregular[j][1] << endl;
																											hasPrinted = true;
																															break;
																																		}
																				}
																if (hasPrinted == true) continue;
																		int length = strlen(words);
																				char output[20] = "";
																						if (words[length-1] == 'y' && (words[length-2] != 'a' && words[length-2] != 'e' && words[length-2] != 'i' && words[length-2] != 'o' && words[length-2] != 'u')) {
																										strncpy(output, words, length-1);
																													strcat(output, "ies");
																																cout << output << endl;
																																		}
																								else if (words[length-1] == 'o' || words[length-1] == 's' || words[length-1] == 'x') {
																												strcpy(output, words);
																															strcat(output, "es");
																																		cout << output << endl;
																																				}
																										else if (words[length-2] == 'c' && words[length-1] == 'h') {
																														strcpy(output, words);
																																	strcat(output, "es");
																																				cout << output << endl;
																																						}
																												else if(words[length-2] == 's' && words[length-1] == 'h'){
																																strcpy(output, words);
																																			strcat(output, "es");
																																						cout << output << endl;
																																								}
																														else{
																																		strcpy(output, words);
																																					strcat(output, "s");
																																								cout << output << endl;
																																										}
																															}
								return 0;
}
