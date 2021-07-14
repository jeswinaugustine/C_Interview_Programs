/* Tower of Hanoi */

void TowerOfHanoi(int n, char from_peg, char to_peg, char aux_peg) {
    /* if only 1 disk, move from source to destination and return*/
    if (n==1) {
        printf(" Move disk 1 from peg %c to %c \n",from_peg,to_peg);
        return;
    }
    /* move top n-1 disks from A to B using C as aux */
    TowerOfHanoi(n-1,from_peg,aux_peg,to_peg);

    /* move from A to C */
    printf(" Move disk 1 from peg %c to %c \n",from_peg,to_peg);

    /* move remaining disks from B to C */
    TowerOfHanoi(n-1,aux_peg,to_peg,from_peg);

}


int main(){

    int n;
    printf("Enter the number of disks: \n");
    scanf("%d",&n);
    TowerOfHanoi(n,'A','C','B');
    return 0;
}
