import yfinance as yf
import pandas as pd

# Settings
ticker_symbol = 'MSFT'
start = '2023-11-01'
end = '2025-11-01'

#  1. Fetch Data
data = yf.download(ticker_symbol, start=start, end=end)

# 2. Date-Time Features
# We need 'Date' as a column to work with it
data.reset_index(inplace=True)
data['Date'] = pd.to_datetime(data['Date'])

# Extract features from the 'Date' column
data['day_of_month'] = data['Date'].dt.day
data['month'] = data['Date'].dt.month
data['weekday'] = data['Date'].dt.weekday  # Monday=0, Sunday=6

# 3. Lag Features 
# 'shift(1)' gets the value from 1 row before (yesterday)
data['lag_1_day'] = data['Close'].shift(1)
# 'shift(7)' gets the value from 7 rows before (last week)
data['lag_7_days'] = data['Close'].shift(7)

#  4. Rolling Mean Features 
# 'rolling(window=7)' looks at the last 7 days and gets the average
data['rolling_mean_7_day'] = data['Close'].rolling(window=7).mean()
# Same thing, but for a 30-day window
data['rolling_mean_30_day'] = data['Close'].rolling(window=30).mean()

#  5. Clean and Show Output
# Drop rows with empty (NaN) values created by shift() and rolling()
final_data = data.dropna()

# Set 'Date' back as the index for a clean table
final_data.set_index('Date', inplace=True)

# Define which columns we want to see in the final output
columns_to_show = [
    'Close', 
    'day_of_month', 
    'month', 
    'weekday', 
    'lag_1_day', 
    'lag_7_days', 
    'rolling_mean_7_day',
    'rolling_mean_30_day'
]

# Print the first 5 rows
print("\n--- Sample Output (Head) ---")
print(final_data[columns_to_show].head(10))

# Print the last 5 rows
print("\n--- Sample Output (Tail) ---")
print(final_data[columns_to_show].tail(10))




