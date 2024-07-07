from mistralai.client import MistralClient
from mistralai.models.chat_completion import ChatMessage
import os
api_key = os.environ["MISTRAL_API_KEY"]
model = "mistral-tiny"

client = MistralClient(api_key=api_key)

messages = [
    ChatMessage(role="user",
                content="Who is the most renowned French painter?")
]