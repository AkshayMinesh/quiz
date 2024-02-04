#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_QUESTIONS 5

typedef struct {
    char question[256];
    char options[4][64];
    int correct_option;
} Question;

void displayQuestion(Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

int checkAnswer(Question q, int user_answer) {
    return (user_answer == q.correct_option);
}

void processQuiz() {
    Question original_questions[MAX_QUESTIONS] = {
        { "Which bird lays the largest egg?",
          { "Owl", "Ostrich", "Kingfisher", "Woodpecker" },
          2 },
        { "How many legs does a spider have?",
          { "7", "8", "6", "5" },
          2 },
        { "Where does the President of the United States live while in office?",
          { "The White House", "The Parliament", "House of Commons", "Washington DC" },
          1 },
        { "Which state is famous for Hollywood?",
          { "Sydney", "California", "New York", "Paris" },
          2 },
        { "What is a group of lions called?",
          { "Drift", "Pride", "Flock", "Drove" },
          2 }
    };
  
    Question questions[MAX_QUESTIONS];
    memcpy(questions, original_questions, sizeof(original_questions));
    int num_questions = MAX_QUESTIONS;
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int random_index = rand() % num_questions;
        Question current_question = questions[random_index];
        displayQuestion(current_question);

        int user_answer;
        char answer_str[64];
        printf("Enter your answer (1-4): ");
        fgets(answer_str, sizeof(answer_str), stdin);
        sscanf(answer_str, "%d", &user_answer);

        if (checkAnswer(current_question, user_answer)) {
            score++;
        }

        questions[random_index] = questions[num_questions - 1];
        num_questions--;
    }
    printf("%d %d\n", score, MAX_QUESTIONS);
}

int main() {
    srand(time(NULL));
    processQuiz();

    return 0;
}






