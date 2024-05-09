import requests
from bs4 import BeautifulSoup

# Get the HTML content
url = "https://www.tripadvisor.com/Hotel_Review-g29092-d113856-Reviews-Fairfield_by_Marriott_Anaheim_Resort-Anaheim_California.html"

# try catch block so that it can timeout
try:
    response = requests.get(url, timeout=10)  # Set timeout to 10 seconds
    response.raise_for_status()  # Raise an exception for HTTP errors
    html_content = response.text
except requests.exceptions.RequestException as e:
    print("Error fetching HTML content:", e)
    exit()  # Exit the script if an error occurs

# Parse the HTML
soup = BeautifulSoup(html_content, "html.parser")

# Get the aggregate score and recent review
score = soup.find("span", class_="kJyXc P").text.strip()
review = soup.find("span", class_="orRIx Ci _a C ").text.strip()

# Output the score and recent review
print("Aggregate Score:", score)
print("Recent Review:", review)
