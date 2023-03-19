/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Node
{
    char word;
    struct Node *next;
} Node;

void add(struct Node **head, char kata)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    Node *current = *head;
    new_node->word = kata;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node; // head awal
        return;
    }
    while (current->next != NULL)
    {
        current = current->next; // lanjut ke node selanjutnya
    }
    current->next = new_node;
    return;
}

// Fungsi untuk mengecek apakah sebuah kata merupakan isogram
int isIsogram(struct Node *head)
{
    Node *current = head;

    // Loop melalui setiap node dalam linked list
    while (current != NULL)
    {
        Node *temp = current->next;

        // Loop melalui sisa node setelah node yang diperiksa
        while (temp != NULL)
        {
            // Jika ada node dengan data yang sama dengan node yang diperiksa, kata bukan isogram
            if (tolower(current->word) == tolower(temp->word))
            {
                return 0;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return 1;
}

void printLinkedList(int cek, Node *current_node)
{
    if (cek == 0)
    {
        printf("Gabungan kata \"");
        while (current_node != NULL)
        {
            printf("%c", current_node->word);
            current_node = current_node->next; // ganti ke node selanjutnya
        }
        printf("\" bukanlah isogram");
    }
    else{
        printf("Gabungan kata \"");
        while (current_node != NULL)
        {
            printf("%c", current_node->word);
            current_node = current_node->next; // ganti ke node selanjutnya
        }
        printf("\" adalah isogram");        
    }
}

int main()
{
    char kata1[20], kata2[20];
    struct Node *word1 = NULL;
    struct Node *word2 = NULL;

    // Input
    printf("Masukkan kata pertama: ");
    scanf("%s", kata1);
    for (int i = 0; i < strlen(kata1); i++)
    {
        add(&word1, kata1[i]);
    }

    printf("Masukkan kata kedua: ");
    scanf("%s", kata2);
    for (int i = 0; i < strlen(kata2); i++)
    {
        add(&word2, kata2[i]);
    }

    // Cek apakah kata pertama merupakan isogram
    if (isIsogram(word1))
    {
        printf("\nKata pertama adalah isogram\n");
    }
    else
    {
        printf("\nKata pertama bukanlah isogram\n");
    }

    // Cek apakah kata kedua merupakan isogram
    if (isIsogram(word2))
    {
        printf("Kata kedua adalah isogram\n");
    }
    else
    {
        printf("Kata kedua bukanlah isogram\n");
    }

    // Cek apakah gabungan kata juga merupakan isogram
    Node *current = word1;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = word2;
    printLinkedList((isIsogram(word1)),word1);

    return 0;
}
