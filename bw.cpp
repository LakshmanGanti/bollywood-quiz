#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

struct node
{
    char key;
    struct node *left, *right;
};

int search(struct node* root,char key){


   while(root->key != key){

      if(root != NULL) {
        // printf("%c ",root->key);

         //go to left tree
         if(root->key > key){
            root = root->left;
         }//else go to right tree
         else {
            root = root->right;
         }

         //not found
         if(root == NULL){
            return -1;
         }
      }
   }
   return 1;
}
// A utility function to create a new BST node
struct node *newNode(char item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, char key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main(){
    
    system("cls");
    cout<<"\n\t\t\t\t #####       #######     #           #          #        #    #          #     #######        #######       #  ######      ";
    cout<<"\n\t\t\t\t#     #     #       #    #           #           #      #     #          #    #        #     #       #      #        #     ";
    cout<<"\n\t\t\t\t#     #     #       #    #           #            #   #       #          #    #        #     #       #      #        #     ";
    cout<<"\n\t\t\t\t######      #       #    #           #             ###        #    ##    #    #        #     #       #      #        #     ";
    cout<<"\n\t\t\t\t#     #     #       #    #           #              #         #   #  #   #    #        #     #       #      #        #     ";
    cout<<"\n\t\t\t\t#     #     #       #    #           #              #         #  #    #  #    #        #     #       #      #        #     ";
    cout<<"\n\t\t\t\t #####       #######     #########   #########      #         ##        ##     #######        #######       #  #######     ";       
    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t ";
    string q = "WELCOME TO BOLLYWOOD";
     for(int i=0;i<q.size();i++)
     {
        cout<<q[i];
        delay(120);
     }
    cout<<endl<<endl;
    char z;
    cout<<"  \n\n\t\tThis is the conventional movie guessing game in which one is asked to correctly guess each letter one at a time.\n\t\tIf the letter occurs in movie name, the character is displayed, or else the chance is cut and in this way if you are void of remaining chances, game is over."<<endl<<endl;
    cout<<"\n  Press any letter to continue : ";
    cin>>z;
    system("cls");
    char a[][100]=
    {
        "JOHNNY GADDAR",
        "DRISHYAM",
        "VEER ZAARA",
        "RAMAIYA VASTAVAIYA",
        "AE DIL HAI MUSHKIL",
        "SADDA ADDA",
        "NH10",
        "DUM LAGA KE HAISHA",
        "CHAIN KHULI KI MAIN KHULI",
        "PINK",
        "36 CHINA TOWN",
        "FUN2SHH",
        "3 IDIOTS",
        "CHAK DE INDIA",
        "MUNNA BHAI MBBS",
        "KUCHH KUCHH HOTA HAI",
        "ANDAAZ APNA APNA",
        "TAARE ZAMEEN PAR",
        "KHOSHLA KA GHOSLA",
        "PAAN SINGH TOMAR",
        "MR X",
        "1920",
        "D DAY",
        "COCKTAIL",
        "JAJANTARAM MAMANTARAM",
        "LAGAAN",
        "MS DHONI",
        "KOI MIL GYA",
        "ZINDAGI NA MILEGI DOBARA",
        "ROCK ON"
    };
    srand (time(NULL));
    int x = rand()%30;
    string s = a[x];

    struct node *root = NULL;
    root = insert(root,s[0] );

    for(int i=1;i<s.size();i++)
    {
        if(s[i]!=' ')
        insert(root, s[i]);
    }
    string s3 = "bollywood";
    string s2;
    string s4;
    int count = 9;
    for(int i=0;i<s.size();i++)
    {

        if(s[i]==' ')
        {
          s2.push_back('/');
        }
       else 
        {
           s2.push_back('*');
        }
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A'){ s2[i]='A'; }
        if(s[i]=='E'){ s2[i]='E'; }
        if(s[i]=='I'){ s2[i]='I'; }
        if(s[i]=='O'){ s2[i]='O'; }
        if(s[i]=='U'){ s2[i]='U'; }
    }
    cout<<"Your movie is"<<endl;
    cout<<s2<<endl;
    while(1)
    {
        fflush(stdin);
        char ch;
        cout<<"Enter a character to find : ";
        cin>>ch;
        Beep(850, 800);
        ch = toupper(ch);
        if(search(root,ch)==-1)
        {
            for(int j=0;j<9;j++)
            {
                if(s3[j]!='*')
                {s3[j]='*';
                break;}
            }
            s4.push_back(ch);
            cout<<"Sorry the character was not present in the string"<<endl;
            cout<<"Characters left : "<<s3<<endl;
            cout<<"Wrong Entries : "<<s4<<endl;
            cout<<"Film Status: "<<s2<<endl;

            count--;
            cout<<endl;
        }
        else
        {
          for(int i=0;i<s.size();i++)
            {
              if(s[i]==ch)
                {
                  s2[i]=ch;
                }
            }

          cout<<"Character found!!"<<endl;
          cout<<"Characters left : "<<s3<<endl;
          cout<<"Wrong Entries : "<<s4<<endl;
          cout<<"Film Status: "<<s2<<endl;

          cout<<endl;

        }
        if(count==0)
        { 
            cout<<"Sorry! You ran out of chances"<<endl;
            cout<<"Movie was: "<<s<<endl;
            break;
        }
        if(find(s2.begin(),s2.end(),'*')==s2.end())
        {

           cout<<"Congrats!!"<<endl;
           cout<<"You guessed it right"<<endl;
           cout<<"The film was : "<<s<<endl;
           break;
        }

    }



    return 0;
}