#Quantij task 1
import random
def random_value(dice_list):
    return random.choice(dice_list)

if __name__ == "__main__":
    dice_list = [1,2,3,4,5,6]
    total = 0
    total_trials = 10000
    for i in range(total_trials):
        total += random_value(dice_list)
    print("Expected value of a die role is : ",total/total_trials)
