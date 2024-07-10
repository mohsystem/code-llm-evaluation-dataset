from mistralai.client import MistralClient
from mistralai.models.chat_completion import ChatMessage


class MistralIntegration:
    def __init__(self, model_name="codestral-latest"):
        # https://mistral.ai/technology/
        # https://docs.mistral.ai/api/#operation/createFIMCompletion
        # https://github.com/mistralai/client-python?tab=readme-ov-file
        # https://docs.mistral.ai/getting-started/clients/
        # https://console.mistral.ai/billing/

        self.api_key = "iWYGhriZX49bCPAeJdogLvYtDVgiBWwA"
        self.model = model_name
        self.client = MistralClient(api_key=self.api_key)

    def generate_content(self, prompt_desc):
        chat_response = self.client.chat(
            model=self.model,
            messages=[ChatMessage(role="user", content=prompt_desc)]
        )
        return chat_response.choices[0].message.content