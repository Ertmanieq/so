/* program echuj±cy argumenty wiersza poleceñ
 */

main(int argc, char **argv) {

  while(--argc > 0)
    printf("%s ", *++argv);
  printf("\n");
}
