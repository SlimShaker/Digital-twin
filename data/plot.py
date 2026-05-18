import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

def load_data():
    df1 = pd.read_csv("latency.csv")
    df2 = pd.read_csv("latency2.csv")
    df = pd.concat([df1, df2], ignore_index=True)
    df.columns = ["id", "edgeSent", "cloudReceived", "e2f", "proc", "f2c", "total", "weight", "device"]
    df = df[df["total"] > 0]
    df = df[df["total"] < 1000]
    print(df)
    return df

def plot_boxplot(df):
    fig, ax = plt.subplots(figsize=(8, 5))
    data = [df[df["device"]==d]["total"].values for d in ["home", "work", "mobile"]]
    ax.boxplot(data, labels=["home\n(via fog1)", "work\n(via fog2)", "mobile\n(direkt)"])
    ax.set_title("Total Latens per Edge-nod")
    ax.set_ylabel("Latens (ms)")
    ax.grid(True, linestyle="--", alpha=0.4)
    plt.savefig("boxplot_total.png", dpi=300, bbox_inches="tight")
    plt.show()

def plot_bar(df):
    devices = ["home", "work", "mobile"]
    means = [df[df["device"]==d]["total"].mean() for d in devices]
    stds = [df[df["device"]==d]["total"].std() for d in devices]
    fig, ax = plt.subplots(figsize=(8, 5))
    ax.bar(["home\n(via fog1)", "work\n(via fog2)", "mobile\n(direkt)"],
           means, yerr=stds, capsize=5, color=["steelblue","orange","green"], alpha=0.7)
    ax.set_title("Medelvärde Total Latens med Standardavvikelse")
    ax.set_ylabel("Latens (ms)")
    ax.grid(True, linestyle="--", alpha=0.4, axis="y")
    plt.savefig("bar_total.png", dpi=300, bbox_inches="tight")
    plt.show()

def plot_e2f_bar(df):
    devices = ["home", "work"]
    means = [df[df["device"]==d]["e2f"].mean() for d in devices]
    stds = [df[df["device"]==d]["e2f"].std() for d in devices]
    fig, ax = plt.subplots(figsize=(6, 5))
    ax.bar(["home\n(fog1)", "work\n(fog2)"], means, yerr=stds,
           capsize=5, color=["steelblue","orange"], alpha=0.7)
    ax.set_title("Edge-to-Fog Latens")
    ax.set_ylabel("Latens (ms)")
    ax.grid(True, linestyle="--", alpha=0.4, axis="y")
    plt.savefig("bar_e2f.png", dpi=300, bbox_inches="tight")
    plt.show()

def print_stats(df):
    print("\nStatistik: ")
    for device in ["home", "work", "mobile"]:
        subset = df[df["device"]==device]
        print(f"\n{device}:")
        print(f"  total  — medel: {subset['total'].mean():.1f}, std: {subset['total'].std():.1f}, min: {subset['total'].min():.1f}, max: {subset['total'].max():.1f}")
        print(f"  e2f    — medel: {subset['e2f'].mean():.1f}, std: {subset['e2f'].std():.1f}")
        print(f"  f2c    — medel: {subset['f2c'].mean():.1f}, std: {subset['f2c'].std():.1f}")

def main():
    df = load_data()
    print_stats(df)
    plot_boxplot(df)
    plot_bar(df)
    plot_e2f_bar(df)

if __name__ == "__main__":
    main()