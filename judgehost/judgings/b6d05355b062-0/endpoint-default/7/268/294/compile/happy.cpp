#include <stdio.h>
#include <string.h>
int main(void) {
	    int testcase, input, i, ans, sum;
	        scanf("%d", &testcase);
		    for (i = 1; i <= testcase; i++){
			            scanf("%d", &input);
				            sum = 0;
					            ans = input;
						            while (ans != 0){
								                sum = sum + (ans % 10) * (ans % 10);
										            ans = ans / 10;

											            }
							            ans = sum; //S1
								            int check[1000] = { 0 };
									            check[1] = 1;
										            while (!check[ans]){

												                check[ans] = 1;
														            sum = 0;
															                while (ans != 0){
																		                sum = sum + (ans % 10) * (ans % 10);
																				                ans = ans / 10;
																						            }
																	            ans = sum;
																		            }
											            if (ans == 1)
													                printf("Case #%d: %d is a Happy number.\n", i, input);
												            else
														                printf("Case #%d: %d is an Unhappy number.\n", i, input);

													        }

		        return 0;
}
