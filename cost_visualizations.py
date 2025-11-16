import sys
import pandas as pd
import matplotlib.pyplot as plt

#running from terminal to test :
# cd /Users/elliesheppard/Desktop/M30EP-eesheppa
# python3 cost_visualizations.py cmake-build-debug/feed_costs.csv

def plot_individual(file):
    try:
        df = pd.read_csv(file, skiprows = 1)
    except FileNotFoundError:
        print("Error, could not find file")
        sys.exit(1)
    prices = df.iloc[0, 1:].astype(float)
    df = df.drop(index = 0)
    horses = df.iloc[:, 0]
    amounts = df.iloc[:, 1:].astype(float)
    costs = (amounts / 50 * prices).sum(axis = 1)

    plt.figure(figsize=(10, 5))
    plt.bar(horses, costs, color='purple', alpha=0.7)
    plt.title("Horse vs Monthly Cost")
    plt.xlabel("Horse")
    plt.ylabel("Monthly Cost")
    plt.grid(axis='y', linestyle='--', alpha=0.5)
    plt.tight_layout()
    plt.show()


def plot_spend_per_grain(file):
    try:
        df = pd.read_csv(file, skiprows = 1)
    except FileNotFoundError:
        print("Error, could not find file")
        sys.exit(1)
    price_row = df[df.iloc[:, 0] == "Price"].iloc[0]
    prices = price_row[1:].astype(float)
    horses = df[df.iloc[:, 0] != "Price"]
    horse_amounts = horses.iloc[:, 1:].astype(float)

    grain_totals = (horse_amounts / 50 * prices).sum(axis = 0)
    grain_totals *= 4.5

    plt.figure(figsize=(10, 5))
    plt.bar(grain_totals.index, grain_totals.values, color='purple', alpha=0.7)
    plt.title("Monthly Cost by Grain Type")
    plt.xlabel("Grain Type")
    plt.ylabel("Cost")
    plt.grid(axis='y', linestyle='--', alpha=0.5)
    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 cost_visualizations.py <csvfile>")
        sys.exit(1)

    filename = sys.argv[1]
    plot_individual(filename)
    plot_spend_per_grain(filename)
