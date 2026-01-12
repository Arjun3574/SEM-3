

def diagnose(symptoms):
    """
    symptoms: set of strings representing car warnings/symptoms
    returns: list of matching fault diagnoses
    """
    rules = [
        ({"engine_light", "knocking_noise"},   "Engine Knock"),
        ({"low_oil_pressure", "high_mileage"}, "Oil Wear"),
        ({"battery_warning", "clicking_noise"},"Dead Battery"),
        ({"overheating", "engine_light"},      "Overheating Engine"),
        ({"brake_warning", "ABS_light"},       "Brake System Fault"),
        ({"tire_pressure_low", "high_mileage"},"Tire Tread Wear"),
        ({"engine_light", "low_oil_pressure"}, "Oil Leak"),
        ({"overheating", "low_oil_pressure"},  "Coolant Leak"),
        ({"clicking_noise", "brake_warning"},  "Brake Pump Issue"),
        ({"battery_warning", "engine_light"},  "Charging System Issue"),
    ]

    matches = []
    for condition, fault in rules:
        if condition.issubset(symptoms):
            matches.append(fault)
    return matches or ["No fault detected."]


if __name__ == "__main__":
    print("Welcome to the Automobile Fault-Diagnosis Expert System\n")
    raw = input("Enter observed car symptoms (comma separated): ").lower()
   
    car_symptoms = {
        s.strip().replace(" ", "_")
        for s in raw.split(",")
        if s.strip()
    }

    results = diagnose(car_symptoms)
    print("\nPossible Diagnoses based on your input:")
    for r in results:
        print("-", r)