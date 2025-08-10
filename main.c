#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// function prototypes
void display_menu();
void random_probability_generator();
void deterministic_calculator();
void coin_toss_simulation();
void dice_roll_simulation();
void card_draw_simulation();
long long compute_factorial(int n);
double compute_poisson_probability(double lambda, int k);
double compute_binomial_probability(int n, int k, double p);
void compute_statistical_measures();

// compute_factorial function
long long compute_factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// display_menu function
void display_menu() {
    printf("\n=== Probability Simulator ===\n");
    printf("1. Random Probability Generator\n");
    printf("2. Deterministic Calculator\n");
    printf("3. Exit\n");
}

// main function
int main() {
    srand((unsigned int)time(0)); // seed for random number generator
    int user_choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                random_probability_generator();
                break;
            case 2:
                deterministic_calculator();
                break;
            case 3:
                printf("Thank you for using Probability Simulator! Goodbye.\n");
                return 0;
            default:
                printf("Invalid choice. Please select valid option.\n");
        }
    }
}

// random_probability_generator function
void random_probability_generator() {
    int generator_choice;
    printf("\n--- Random Probability Generator ---\n");
    printf("1. Coin Toss Simulation\n");
    printf("2. Dice Roll Simulation\n");
    printf("3. Card Draw Simulation\n");
    printf("4. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &generator_choice);

    switch (generator_choice) {
        case 1:
            coin_toss_simulation();
            break;
        case 2:
            dice_roll_simulation();
            break;
        case 3:
            card_draw_simulation();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Please select valid option.\n");
    }
}

// deterministic_calculator function
void deterministic_calculator() {
    int calculator_choice;
    printf("\n--- Deterministic Calculator ---\n");
    printf("1. Binomial Distribution Probability\n");
    printf("2. Poisson Distribution Probability\n");
    printf("3. Statistical Measures\n");
    printf("4. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &calculator_choice);

    switch (calculator_choice) {
        case 1: {
            int trials, successes;
            double success_probability;
            printf("\nEnter number of trials (n): ");
            scanf("%d", &trials);
            printf("Enter number of successes (k): ");
            scanf("%d", &successes);
            printf("Enter probability of success (p): ");
            scanf("%lf", &success_probability);
            printf("Binomial Probability: %.6f\n", compute_binomial_probability(trials, successes, success_probability));
            break;
        }
        case 2: {
            double event_rate;
            int occurrences;
            printf("\nEnter average event rate (λ): ");
            scanf("%lf", &event_rate);
            printf("Enter number of occurrences (k): ");
            scanf("%d", &occurrences);
            printf("Poisson Probability: %.6f\n", compute_poisson_probability(event_rate, occurrences));
            break;
        }
        case 3:
            compute_statistical_measures();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Please select valid option.\n");
    }
}

// coin_toss_simulation function
void coin_toss_simulation() {
    int tosses, heads = 0;
    printf("\n--- Coin Toss Simulation ---\n");
    printf("Enter number of tosses: ");
    scanf("%d", &tosses);

    for (int i = 0; i < tosses; i++) {
        heads += rand() % 2;
    }

    printf("Results: Heads = %d, Tails = %d\n", heads, tosses - heads);
}

// dice_roll_simulation function
void dice_roll_simulation() {
    int rolls, dice_outcomes[6] = {0};
    printf("\n--- Dice Roll Simulation ---\n");
    printf("Enter number of rolls: ");
    scanf("%d", &rolls);

    for (int i = 0; i < rolls; i++) {
        dice_outcomes[rand() % 6]++;
    }

    printf("\nFace\tFrequency\n");
    for (int i = 0; i < 6; i++) {
        printf("%d\t%d\n", i + 1, dice_outcomes[i]);
    }
}

// card_draw_simulation function
void card_draw_simulation() {
    int draws, card_outcomes[4] = {0};
    const char *card_suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    printf("\n--- Card Draw Simulation ---\n");
    printf("Enter number of card draws: ");
    scanf("%d", &draws);

    for (int i = 0; i < draws; i++) {
        card_outcomes[rand() % 4]++;
    }

    printf("\nSuit\tFrequency\n");
    for (int i = 0; i < 4; i++) {
        printf("%s\t%d\n", card_suits[i], card_outcomes[i]);
    }
}

// compute_binomial_probability function
double compute_binomial_probability(int n, int k, double p) {
    return (compute_factorial(n) / (compute_factorial(k) * compute_factorial(n - k))) * pow(p, k) * pow(1 - p, n - k);
}

// compute_poisson_probability function
double compute_poisson_probability(double lambda, int k) {
    return (pow(lambda, k) * exp(-lambda)) / compute_factorial(k);
}

// compute_statistical_measures function
void compute_statistical_measures() {
    int data_points_count;
    printf("\n--- Statistical Measures ---\n");
    printf("Enter number of data points: ");
    scanf("%d", &data_points_count);

    double data_points[data_points_count], sum = 0, variance = 0;
    printf("Enter data points:\n");
    for (int i = 0; i < data_points_count; i++) {
        scanf("%lf", &data_points[i]);
        sum += data_points[i];
    }

    double mean = sum / data_points_count;
    for (int i = 0; i < data_points_count; i++) {
        variance += pow(data_points[i] - mean, 2);
    }
    variance /= data_points_count;

    printf("\nResults:\n");
    printf("Mean: %.2f\nVariance: %.2f\nStandard Deviation: %.2f\n", mean, variance, sqrt(variance));
}
