// Reduced Row Echelon Form (RREF)
#include <stdio.h>
#include <math.h>


void matrix(double em[6][6], int m, int n){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element (%d,%d):  ", i+1,j+1);
            scanf("%lf", &em[i][j]);
        }
        printf("\n");
    }
}

void show_em(double em[6][6], int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if (em[i][j] == -0)
                em[i][j] = 0;
            
            printf("%.0f ", em[i][j]); 
        }
        printf("\n");
    }
    printf("\n");
}

void swap_row(double em[6][6], int rows, int cols, int sr, int sr_with){
    int temp;   
    for(int j = 0; j < cols; j++){
        temp = em[sr][j];
        em[sr][j] = em[sr_with][j];
        em[sr_with][j] = temp; 
    }    
}

void div_row(double em[6][6], int rows, int cols,int sr, int lambda){

        for(int j = 0; j < cols; j++){
            em[sr][j] /= lambda;
        }
    
}

void row_reduce(double em[6][6], int rows, int cols) {
    int lead = 0;  // Pivot column index

    for (int r = 0; r < rows; r++) {
        if (lead >= cols) //Exits the code if it runs outside the column length.
            return;
        
        int i = r;
        // Step 1: Find a non-zero pivot and swap if necessary
        while (em[i][lead] == 0) {
            i++;
            if (i == rows) {
                i = r;
                lead++;
                if (lead == cols)
                    return;
            }
        }

        // Swap the current row with the row of the pivot
        if (i != r) {
            swap_row(em, rows, cols, i, r);
        }

        // Step 2: Normalize the pivot row
        double pivot = em[r][lead];
        if (pivot != 0) {

            div_row(em, rows, cols, r, pivot);
        }

        // Step 3: Eliminate entries below the pivot
        for (i = 0; i < rows; i++) {
            if (i != r) {
                double factor = em[i][lead];
                for (int k = 0; k < cols; k++) {
                    em[i][k] = em[i][k] - factor * em[r][k];
                }
            }
        }
        
        lead++;
    }
}

int main(){
    //int rows = 4, cols = 4;
    
    
   //Example em
    //double em[6][6] = {{0,0,4,1},{0,3,0,1},{0,0,0,0},{0,4,2,0}};
    
    int rows, cols;
    printf("Enter the em : m X n\n");
    scanf("%d %d", &rows ,&cols);
    double em[6][6];
    matrix(em,rows,cols);
    

    show_em(em, rows, cols);

    row_reduce(em, rows, cols);
    show_em(em, rows, cols);
    
    return 0;
}
