import anthropic


class ClaudeIntegration:
    def __init__(self, model_name):
        # https://docs.anthropic.com/en/docs/about-claude/models
        # https://console.anthropic.com/settings/plans
        self.model = model_name
        SESSION_KEY = "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"
        self.client = anthropic.Anthropic(api_key=SESSION_KEY,)

    def generate_content(self, prompt_system, prompt_desc):
        message = self.client.messages.create(
            model=self.model,
            max_tokens=4096,
            temperature=0,
            system=prompt_system,
            messages=[
                {
                    "role": "user",
                    "content": [
                        {
                            "type": "text",
                            "text": prompt_desc
                        }
                    ]
                }
            ]
        )
        return message.content
