import base64
import json

def process_request(raw_data: str) -> str:
    """
    Processes incoming requests.

    Args:
        raw_data: The raw data from the request.

    Returns:
        The processed data.
    """
    # Decode the raw_data using Base64
    decoded_data = base64.b64decode(raw_data).decode("utf-8")

    # Deserialize the decoded data into its original format
    # deserialized_data = json.loads(decoded_data)  # Example for JSON deserialization

    return decoded_data


if __name__ == "__main__":
    raw_data = "eyJtZXNzYWdlIjogIkhlbGxvIHdvcmxkIn0="
    processed_data = process_request(raw_data)
    print(processed_data)