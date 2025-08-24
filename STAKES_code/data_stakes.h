
QStringList for_list_companies = {
    "GlobalSoft Ltd.", "EcoFuture Solutions", "GreenWave Systems", "AlphaTech Corp.",
    "MicroData Co.", "PrimeCore Technologies", "QuantumSoft Enterprises", "XenonX Labs",
    "SkyNet Innovations", "NextGen Digital", "CyberLink Industries", "CrystalPeak Technologies",
    "RedFox Ventures", "Vanguard Electronics", "SilverEdge Networks", "BlueWave Global",
    "Nimbus Enterprises", "Phoenix Solutions", "MegaByte Corporation", "Sunrise Innovations",
    "CyberDyne Labs", "RedStone Technologies", "Infinite Horizon Ltd.", "QuantumWave Solutions",
    "NanoTech Industries", "GlobeX Digital", "ZeroPoint Ventures", "CyberSage Enterprises",
    "FusionEdge Systems", "TechnoCore Inc."
};







QString company_names[30]= { "GlobalSoft Ltd.", "EcoFuture Solutions", "GreenWave Systems", "AlphaTech Corp.",
    "MicroData Co.", "PrimeCore Technologies", "QuantumSoft Enterprises", "XenonX Labs", "SkyNet Innovations",
    "NextGen Digital", "CyberLink Industries", "CrystalPeak Technologies", "RedFox Ventures", "Vanguard Electronics",
    "SilverEdge Networks", "BlueWave Global", "Nimbus Enterprises", "Phoenix Solutions", "MegaByte Corporation",
    "Sunrise Innovations", "CyberDyne Labs", "RedStone Technologies", "Infinite Horizon Ltd.", "QuantumWave Solutions",
    "NanoTech Industries", "GlobeX Digital", "ZeroPoint Ventures", "CyberSage Enterprises", "FusionEdge Systems","TechnoCore Inc."
};
float stock_prices[30] = {
    212.89f, 54.32f, 98.76f, 134.21f,
    87.45f, 223.67f, 191.23f, 159.45f, 189.32f,
    312.50f, 450.20f, 76.88f, 130.15f, 278.60f,
    65.70f, 122.90f, 234.75f, 191.12f, 95.48f,
    410.11f, 99.30f, 234.50f, 167.80f, 220.60f,
    107.20f, 260.10f, 139.99f, 315.25f,214.41f ,124.53f
};
float risk_factors[30] = {
    0.0067f, 0.0012f, 0.0078f, 0.0055f,
    0.0040f, 0.0076f, 0.0060f, 0.0049f, 0.0081f,
    0.0033f, 0.0070f, 0.0027f, 0.0055f, 0.0064f,
    0.0072f, 0.0029f, 0.0058f, 0.0077f, 0.0045f,
    0.0065f, 0.0042f, 0.0079f, 0.0051f, 0.0063f,
    0.0060f, 0.0035f, 0.0066f, 0.0039f, 0.0056f,  0.0034f
};

QString cryptoNames[30] = {
    "Bitcoin", "Ethereum", "Binance Coin", "Cardano", "Solana",
    "XRP", "Polkadot", "Dogecoin", "Litecoin", "Avalanche",
    "Shiba Inu", "Chainlink", "Uniswap", "Polygon", "VeChain",
    "Cosmos", "Tezos", "Algorand", "Filecoin", "FTX Token",
    "Stellar", "Tron", "Ethereum Classic", "Aave", "Maker",
    "SushiSwap", "Terra", "Kusama", "Harmony", "Zcash"};

float cryptoPrices[30] = {
    31500.00f, 2100.50f, 410.00f, 2.10f, 38.60f,
    0.52f, 42.35f, 0.068f, 150.00f, 63.40f,
    0.0000095f, 27.60f, 21.50f, 1.45f, 0.12f,
    28.75f, 5.30f, 1.70f, 70.00f, 35.50f,
    0.10f, 0.085f, 35.25f, 325.70f, 5800.20f,
    6.75f, 34.90f, 0.15f, 0.18f, 134.50f
};

float cryptoRiskFactors[30] = {
    0.075f, 0.070f, 0.05f, 0.080f, 0.085f,
    0.090f, 0.070f, 0.095f, 0.060f, 0.075f,
    0.085f, 0.065f, 0.055f, 0.080f, 0.075f,
    0.060f, 0.065f, 0.050f, 0.085f, 0.065f,
    0.090f, 0.095f, 0.075f, 0.060f, 0.070f,
    0.085f, 0.080f, 0.060f, 0.075f, 0.090f
};
QList<QPair<QString, QPair<float, float>>> properties = {
    {"Studio Apartment", {80000.0f, 1200.0f}},       // ROI: 1.5%
    {"1 Bedroom Apartment", {120000.0f, 1800.0f}},   // ROI: 1.8%
    {"2 Bedroom Apartment", {150000.0f, 2200.0f}},   // ROI: 1.76%
    {"3 Bedroom Apartment", {180000.0f, 2800.0f}},   // ROI: 1.87%
    {"Loft", {220000.0f, 3000.0f}},                   // ROI: 1.64%
    {"Penthouse", {350000.0f, 5000.0f}},              // ROI: 1.71%
    {"Microhouse", {50000.0f, 800.0f}},               // ROI: 1.92%
    {"Tiny House", {75000.0f, 1000.0f}},              // ROI: 1.6%
    {"Small House", {120000.0f, 1800.0f}},            // ROI: 1.8%
    {"Cottage", {100000.0f, 1500.0f}},                // ROI: 1.8%
    {"Bungalow", {150000.0f, 2000.0f}},               // ROI: 1.6%
    {"Townhouse", {200000.0f, 2500.0f}},              // ROI: 1.5%
    {"Duplex", {250000.0f, 3000.0f}},                 // ROI: 1.44%
    {"Villa", {300000.0f, 4000.0f}},                  // ROI: 1.6%
    {"Ranch House", {250000.0f, 3500.0f}},            // ROI: 1.68%
    {"Cottage House", {120000.0f, 1800.0f}},          // ROI: 1.8%
    {"Chalet", {130000.0f, 1900.0f}},                 // ROI: 1.76%
    {"Beach House", {300000.0f, 4500.0f}},            // ROI: 1.8%
    {"Cabin", {90000.0f, 1300.0f}},                   // ROI: 1.73%
    {"Farmhouse", {200000.0f, 2500.0f}},              // ROI: 1.5%
    {"Suburban House", {220000.0f, 3000.0f}},         // ROI: 1.64%
    {"Urban House", {250000.0f, 3500.0f}},            // ROI: 1.68%
    {"Row House", {170000.0f, 2400.0f}},               // ROI: 1.69%
    {"Condo", {220000.0f, 3200.0f}},                  // ROI: 1.75%
    {"Apartment Unit", {150000.0f, 2000.0f}},         // ROI: 1.6%
    {"Maisonette", {270000.0f, 3500.0f}},             // ROI: 1.55%
    {"Terraced House", {160000.0f, 2200.0f}},         // ROI: 1.65%
    {"Triplex", {280000.0f, 3700.0f}},                // ROI: 1.58%
    {"Quadplex", {350000.0f, 4500.0f}},               // ROI: 1.54%
    {"Garden House", {140000.0f, 2100.0f}},           // ROI: 1.8%
    {"Luxury House", {500000.0f, 7000.0f}},           // ROI: 1.68%
    {"Designer House", {550000.0f, 8000.0f}},         // ROI: 1.74%
    {"Smart Home", {450000.0f, 6500.0f}},             // ROI: 1.73%
    {"Eco Home", {350000.0f, 5000.0f}},               // ROI: 1.71%
    {"Mountain Retreat", { 600000.0f, 9000.0f}}, // ROI: 1.5%
    {"Lakefront Property", {800000.0f, 12000.0f}}, // ROI: 1.5%
    {"Penthouse Suite", {700000.0f, 10000.0f}}, // ROI: 1.43%
    {"Co-living Apartment", {80000.0f, 1200.0f}}, // ROI: 1.8%
    {"Cooperative Apartment", {180000.0f, 2500.0f}}, // ROI: 1.67%
    {"Holiday Home", {250000.0f, 3500.0f}}, // ROI: 1.68%
    {"Bungalow House", {200000.0f, 3000.0f}}, // ROI: 1.8%
    {"Shared Apartment", {60000.0f, 900.0f}}, // ROI: 1.8%
    {"Hostel Room", {20000.0f, 400.0f}}, // ROI: 2.4%
    {"Guest House", {100000.0f, 1500.0f}}, // ROI: 1.8%
    {"Rural Cottage", {80000.0f, 1200.0f}}, // ROI: 1.8%
    {"Patio Home", {230000.0f, 3000.0f}}, // ROI: 1.57%
    {"Modular Home", {150000.0f, 2200.0f}}, // ROI: 1.76%
    {"Prefab House", {120000.0f, 1800.0f}}, // ROI: 1.8%
    {"Shipping Container Home", {100000.0f, 1500.0f}}, // ROI: 1.8%
    {"Eco-Friendly House", {400000.0f, 6000.0f}}, // ROI: 1.8%
    {"Container Apartment", {120000.0f, 1800.0f}}, // ROI: 1.8%
    {"Houseboat", {180000.0f, 2500.0f}}, // ROI: 1.67%
    {"Barn Conversion", {250000.0f, 3500.0f}}, // ROI: 1.68%
    {"Converted Warehouse", {300000.0f, 4000.0f}}, // ROI: 1.6%
    {"Apartment Complex", {180000.0f, 2500.0f}}, // ROI: 1.67%
    {"Studio Condo", {220000.0f, 3200.0f}}, // ROI: 1.75%
    {"Luxury Condo", {350000.0f, 5000.0f}}, // ROI: 1.71%
    {"High-Rise Apartment", {450000.0f, 6500.0f}}, // ROI: 1.73%
    {"Suburban Condo", {250000.0f, 3500.0f}}, // ROI: 1.68%
    {"Townhouse Complex", {290000.0f, 4000.0f}}, // ROI: 1.55%
    {"Mixed-Use Building", {400000.0f, 6000.0f}}, // ROI: 1.5%
    {"Luxury Duplex", {500000.0f, 7000.0f}}, // ROI: 1.68%
    {"Serviced Apartment", {300000.0f, 4500.0f}}, // ROI: 1.8%
    {"Mobile Home", {80000.0f, 1200.0f}}, // ROI: 1.8%
    {"Tiny Living Space", {50000.0f, 800.0f}}, // ROI: 1.92%
    {"Compact Living Unit", {100000.0f, 1500.0f}}, // ROI: 1.8%
    {"Holiday Villa", {700000.0f, 10000.0f}}, // ROI: 1.43%
    {"Luxury Penthouse", {900000.0f, 13000.0f}}, // ROI: 1.44%
    {"Villa Complex", {1100000.0f, 15000.0f}}, // ROI: 1.36%
    {"Apartment Block", {150000.0f, 2000.0f}}, // ROI: 1.6%
    {"Mansion", {1500000.0f,  20000.0f}}, // ROI: 1.33%
    {"Gated Community House", {700000.0f, 10000.0f}}, // ROI: 1.43%
    {"Smart Apartment", {500000.0f, 7000.0f}}, // ROI: 1.68%
    {"Converted Loft", {250000.0f, 3500.0f}}, // ROI: 1.68%
    {"Historic House", {400000.0f, 6000.0f}}, // ROI: 1.5%
    {"Urban Loft", {350000.0f, 5000.0f}}, // ROI: 1.71%
    {"Sky Suite", {1200000.0f, 18000.0f}}, // ROI: 1.5%
    {"Skyline Mansion", {1800000.0f, 25000.0f}}, // ROI: 1.39%
    {"Seafront Villa", {1200000.0f, 18000.0f}}, // ROI: 1.5%
    {"Luxury Duplex Apartment", {1000000.0f, 15000.0f}}, // ROI: 1.5%
    {"Residential Tower", {550000.0f, 8000.0f}}, // ROI: 1.45%
    {"High-Rise Residential Building", {700000.0f, 10000.0f}}, // ROI: 1.43%
    {"Luxury High-Rise", {900000.0f, 13000.0f}}, // ROI: 1.44%
    {"Architectural Building", {1500000.0f, 20000.0f}}, // ROI: 1.33%
    {"Luxury Gated Community", {1300000.0f, 18000.0f}}, // ROI: 1.38%
    {"Executive Office Building", {2000000.0f, 30000.0f}}, // ROI: 1.5%
    {"Corporate Tower", {2500000.0f, 35000.0f}}, // ROI: 1.4%
    {"Medical Office Building", {3000000.0f, 40000.0f}}, // ROI: 1.33%
    {"Retail and Residential Building", {1800000.0f, 25000.0f}}, // ROI: 1.39%
    {"Business Center", {2200000.0f, 30000.0f}}, // ROI: 1.36%
    {"Commercial Building", {1500000.0f, 20000.0f}}, // ROI: 1.33%
    {"Office Complex", {1200000.0f, 18000.0f}}, // ROI: 1.33%
    {"Residential High-Rise", {800000.0f, 12000.0f}}, // ROI: 1.5%
    {"Office Tower", {1500000.0f, 20000.0f}}, // ROI: 1.33%
    {"Residential Skyscraper", {2000000.0f, 30000.0f}}, // ROI: 1.5%
    {"Sky Tower", {2500000.0f, 35000.0f}}, // ROI: 1.4%
    {"Urban High-Rise", {1500000.0f, 20000.0f}}, // ROI: 1.33%
    {"Luxury Sky Residences", {4000000.0f, 60000.0f}}, // ROI
    {"Multifamily Building", {10000.0f, 1500.0f}},            // ROI: 1.33%
    {"Luxury Commercial Building", {30000.0f, 3000.0f}},     // ROI: 1.00%
    {"Industrial Loft", {3500.0f, 800.0f}},                   // ROI: 0.44%
    {"Apartment Tower", {6000.0f, 2000.0f}},                  // ROI: 0.30%
    {"Residential Tower Block", {8000.0f, 2500.0f}},         // ROI: 0.32%
    {"Mega Mansion", {50000.0f, 10000.0f}},                   // ROI: 0.50%
    {"Downtown Skyscraper", {70000.0f, 30000.0f}},           // ROI: 0.23%
    {"Tech Campus", {30000.0f, 50000.0f}},                    // ROI: 0.60%
    {"Luxury Apartments", {10000.0f, 1200.0f}},               // ROI: 0.83%
    {"Business District Tower", {25000.0f, 8000.0f}},         // ROI: 0.31%
    {"Corporate HQ", {60000.0f, 15000.0f}},                   // ROI: 0.40%
    {"Mixed-Use Skyscraper", {35000.0f, 20000.0f}},           // ROI: 0.25%
    {"High-Rise Condominium", {15000.0f, 3000.0f}},           // ROI: 0.50%
    {"Luxury Office Building", {45000.0f, 12000.0f}},         // ROI: 0.38%
    {"Skyline Residential", {22000.0f, 4000.0f}},             // ROI: 0.55%
    {"Multifamily Residential Complex", {8000.0f, 2500.0f}},  // ROI: 0.32%
    {"Residential Block Tower", {7000.0f, 2200.0f}},          // ROI: 0.32%
    {"Shopping Center", {25000.0f, 5000.0f}},                 // ROI: 0.50%
    {"Sky Residence Complex", {35000.0f, 18000.0f}},          // ROI: 0.19%
    {"Luxury Living Complex", {40000.0f, 10000.0f}},          // ROI: 0.40%
    {"Apartment Building with Retail", {18000.0f, 3500.0f}},  // ROI: 0.51%
    {"Master-Planned Community", {50000.0f, 20000.0f}},      // ROI: 0.25%
    {"Luxury Estate", {120000.0f, 30000.0f}},                  // ROI: 0.40%
    {"Shopping Mall Complex", {50000.0f, 50000.0f}},          // ROI: 1.00%
    {"Luxury Waterfront Property", {70000.0f, 12000.0f}},     // ROI: 0.58%
    {"Office Park", {22000.0f, 10000.0f}},                     // ROI: 0.22%
    {"Luxury Hotel Tower", {35000.0f, 15000.0f}},              // ROI: 0.23%
    {"Exclusive Gated Residence", {90000.0f, 25000.0f}},      // ROI: 0.36%
    {"Luxury Resort Building", {150000.0f, 50000.0f}},        // ROI: 0.30%
    {"Grand Office Building", {120000.0f, 20000.0f}},         // ROI: 0.60%
    {"Residential Community", {10000.0f, 1500.0f}},            // ROI: 0.67%
    {"Urban Housing Complex", {15000.0f, 4000.0f}},           // ROI: 0.38%
    {"Luxury Shopping Plaza", {30000.0f, 8000.0f}}           // ROI: 0.38%
};
QList<QPair< int ,QPair< QString , double >>> news =
    {{30 , {"TechnoCore Inc. announces breakthrough AI technology!", 10}},   // Positive news, +10% increase
        {1 , {"GlobalSoft Ltd. faces cyberattack, data breach reported.", -8}}, // Negative news, -8% decrease
        {2 , {"EcoFuture Solutions secures massive green energy project.", 12}}, // Positive news, +12% increase
        {3 , {"GreenWave Systems reports delay in their electric vehicle release.", -5}}, // Negative news, -5% decrease
        {4 , {"AlphaTech Corp. partners with NASA for next-gen satellite technology.", 15}}, // Positive news, +15% increase
        {5 , {"MicroData Co. faces class action lawsuit for defective product.", -7}}, // Negative news, -7% decrease
        {6 , {"PrimeCore Technologies announces strong quarterly earnings.", 6}}, // Positive news, +6% increase
        {7 , {"QuantumSoft Enterprises loses a major client, stock down.", -10}}, // Negative news, -10% decrease
        {8 , {"XenonX Labs receives government grant for innovative medical research.", 8}}, // Positive news, +8% increase
        {9 , {"SkyNet Innovations' self-driving car project faces regulatory challenges.", -6}}, // Negative news, -6% decrease
        {10 , {"NextGen Digital launches a new social media platform with huge user base.", 10}}, // Positive news, +10% increase
        {11 , {"CyberLink Industries reports poor earnings for the second quarter.", -9}}, // Negative news, -9% decrease
        {12 , {"CrystalPeak Technologies enters the virtual reality market, stocks surge.", 14}}, // Positive news, +14% increase
        {13 , {"RedFox Ventures hits financial troubles due to market crash.", -12}}, // Negative news, -12% decrease
        {14 , {"Vanguard Electronics sees record sales in new smartphone model.", 20}}, // Positive news, +20% increase
        {15 , {"SilverEdge Networks' CEO resigns amid allegations of fraud.", -15}}, // Negative news, -15% decrease
        {16 , {"BlueWave Global enters the renewable energy sector, positive growth expected.", 18}}, // Positive news, +18% increase
        {17 , {"Nimbus Enterprises expands into international markets, stocks rise.", 11}}, // Positive news, +11% increase
        {18 , {"Phoenix Solutions acquires a major competitor, dominating the market.", 13}}, // Positive news, +13% increase
        {19 , {"MegaByte Corporation faces a major recall of defective products.", -8}}, // Negative news, -8% decrease
        {20 , {"Sunrise Innovations reports record profits in Q1.", 9}}, // Positive news, +9% increase
        {21 , {"CyberDyne Labs' robot technology gains massive interest from military.", 17}}, // Positive news, +17% increase
        {22 , {"RedStone Technologies experiences major layoffs after merger failure.", -10}}, // Negative news, -10% decrease
        {23 , {"Infinite Horizon Ltd. cancels a highly anticipated product launch.", -5}}, // Negative news, -5% decrease
        {24 , {"QuantumWave Solutions wins prestigious industry award.", 10}}, // Positive news, +10% increase
        {25 , {"NanoTech Industries faces a patent dispute with a competitor.", -6}}, // Negative news, -6% decrease
        {26 , {"GlobeX Digital launches the most advanced cloud storage system.", 12}}, // Positive news, +12% increase
        {27 , {"ZeroPoint Ventures drops out of a major industry partnership.", -7}}, // Negative news, -7% decrease
        {28 , {"CyberSage Enterprises achieves massive growth in its cybersecurity sector.", 14}}, // Positive news, +14% increase
        {29 , {"FusionEdge Systems suffers financial losses after failed product launch.", -9}}, // Negative news, -9% decrease
        {30 , {"TechnoCore Inc. reports a 15% increase in Q3 revenue, driven by strong demand for its AI-driven software solutions.", 5.2}},
        {1 , {"GlobalSoft Ltd. announces a strategic partnership with a leading cloud provider, boosting investor confidence.", 3.8}},
        {2 , {"EcoFuture Solutions secures a major contract for sustainable energy projects, leading to a surge in stock prices.", 6.5}},
        {3 , {"GreenWave Systems faces a setback as regulatory challenges delay its new product launch.", -4.1}},
        {4 , {"AlphaTech Corp. unveils a groundbreaking technology in quantum computing, attracting significant media attention.", 8.9}},
        {5 , {"MicroData Co. experiences a data breach, causing concerns among investors.", -7.3}},
        {6 , {"PrimeCore Technologies reports a successful IPO, with shares soaring on the first day of trading.", 12.4}},
        {7 , {"QuantumSoft Enterprises expands its operations into Europe, anticipating a 20% growth in sales.", 4.7}},
        {8 , {"XenonX Labs announces a revolutionary drug trial, sending stock prices skyrocketing.", 9.1}},
        {9 , {"SkyNet Innovations faces a lawsuit over patent infringement, impacting its stock performance.", -5.6}},
        {10 , {"NextGen Digital achieves a milestone of 1 million active users, prompting a positive market reaction.", 7.8}},
        {11 , {"CyberLink Industries launches a new cybersecurity product, leading to increased market share.", 5.5}},
        {12 , {"CrystalPeak Technologies partners with a major telecom provider to enhance its services.", 6.2}},
        {13 , {"RedFox Ventures invests in several promising startups, diversifying its portfolio.", 3.3}},
        {14 , {"Vanguard Electronics reports a decline in sales due to supply chain issues.", -6.8}},
        {15 , {"SilverEdge Networks successfully integrates its services with a major financial institution.", 4.9}},
        {16 , {"BlueWave Global launches an innovative app that gains rapid popularity among consumers.", 10.1}},
        {17 , {"Nimbus Enterprises faces challenges in its international expansion plans, affecting stock prices.", -3.7}},
        {18 , {"Phoenix Solutions announces record profits for the quarter, delighting investors.", 11.5}},
        {19 , {"MegaByte Corporation struggles with outdated technology, leading to a decline in its stock value.", -8.2}},
        {20 , {"Sunrise Innovations receives accolades for its sustainable business practices, boosting its reputation.", 5.6}},
        {21 , {"CyberDyne Labs reports a breakthrough in robotics, attracting interest from major investors.", 9.4}},
        {22 , {"RedStone Technologies faces backlash over its environmental impact, causing stock prices to drop.", -4.5}},
        {23 , {"Infinite Horizon Ltd. successfully enters the Asian market, leading to a significant rise in stock value.", 7.2}},
        {24 , {"QuantumWave Solutions secures funding for a new project, enhancing growth prospects.", 6.0}},
        {25 , {"NanoTech Industries announces a merger with a leading biotech firm, boosting investor confidence.", 8.0}},
        {26 , {"GlobeX Digital launches a new marketing campaign that significantly increases brand awareness.", 9.5}},
        {27 , {"ZeroPoint Ventures faces a management shakeup, leading to uncertainty among investors.", -5.0}},
        {28 , {"CyberSage Enterprises reports a significant increase in cybersecurity threats, boosting demand for its solutions.", 7.4}},
        {29 , {"FusionEdge Systems announces a new partnership with a major automotive manufacturer.", 4.3}},
        {30 , {"TechnoCore Inc. expands its product line, leading to increased market share.", 5.0}},
        {1 , {"GlobalSoft Ltd. faces a cybersecurity breach, causing stock prices to plummet.", -6.5}},
        {2 , {"EcoFuture Solutions partners with a government agency for renewable energy projects.", 7.3}},
        {3 , {"GreenWave Systems reports a quarterly loss due to increased competition.", -4.8}},
        {4 , {"AlphaTech Corp. receives a prestigious award for innovation in technology.", 6.9}},
        {5 , {"MicroData Co. announces layoffs, raising concerns about its financial health.", -5.2}},
        {6 , {"PrimeCore Technologies launches a new software that gains rapid adoption.", 8.4}},
        {7 , {"QuantumSoft Enterprises faces delays in product development, affecting stock performance.", -3.9}},
        {8 , {"XenonX Labs secures a patent for a new drug, boosting investor confidence.", 10.0}},
        {9 , {"SkyNet Innovations reports a successful product launch, exceeding sales expectations.", 9.2}},
        {10 , {"NextGen Digital faces regulatory scrutiny over data privacy issues.", -4.0}},
        {11 , {"CyberLink Industries expands into new markets, increasing its growth potential.", 5.8}},
        {12 , {"CrystalPeak Technologies experiences a decline in customer satisfaction ratings.", -3.5}},
        {13 , {"RedFox Ventures announces a new investment strategy focusing on tech startups.", 4.6}},
        {14 , {"Vanguard Electronics launches a new product line, driving sales growth.", 7.1}},
        {15 , {"SilverEdge Networks faces a lawsuit over service outages, impacting stock prices.", -6.2}},
        {16 , {"BlueWave Global reports record user engagement metrics, boosting stock prices.", 11.0}},
        {17 , {"Nimbus Enterprises announces a strategic acquisition to enhance its service offerings.", 8.5}},
        {18 , {"Phoenix Solutions faces challenges in meeting production targets.", -4.3}},
        {19 , {"MegaByte Corporation invests in new technology to improve efficiency.", 5.4}},
        {20 , {"Sunrise Innovations partners with educational institutions to promote sustainability.", 6.1}},
        {21 , {"CyberDyne Labs reports a successful trial of its latest robotics technology.", 9.7}},
        {22 , {"RedStone Technologies announces a new CEO, leading to mixed investor reactions.", -2.8}},
        {23 , {"Infinite Horizon Ltd. launches a new marketing strategy that significantly boosts sales.", 7.9}},
        {24 , {"QuantumWave Solutions faces delays in project timelines, affecting investor sentiment.", -3.2}},
        {25 , {"NanoTech Industries reports a breakthrough in nanotechnology applications.", 8.8}},
        {26 , {"GlobeX Digital expands its service offerings, attracting new clients.", 6.4}},
        {27 , {"ZeroPoint Ventures announces a new venture fund focused on green technologies.", 5.7}},
        {28 , {"CyberSage Enterprises faces increased competition in the cybersecurity market.", -4.1}},
        {29 , {"FusionEdge Systems reports a significant increase in sales due to new contracts.", 10.3}},
        {30 , {"TechnoCore Inc. launches a new AI product, gaining significant market traction.", 7.5}},
        {1 , {"GlobalSoft Ltd. faces backlash over its handling of user data.", -5.9}},
        {2 , {"EcoFuture Solutions reports a successful quarter, exceeding analyst expectations.", 8.2}},
        {3 , {"GreenWave Systems announces a new sustainability initiative, improving its public image.", 6.0}},
        {4 , {"AlphaTech Corp. partners with a major university for research and development.", 4.8}},
        {5 , {"MicroData Co. faces a class-action lawsuit over privacy violations.", -7.0}},
        {6 , {"PrimeCore Technologies expands its workforce, indicating growth plans.", 5.3}},
        {7 , {"QuantumSoft Enterprises launches a new product line, attracting significant interest.", 9.0}},
        {8 , {"XenonX Labs reports a successful drug trial, leading to a surge in stock prices.", 11.2}},
        {9 , {"SkyNet Innovations announces a new CEO, leading to a positive market reaction.", 6.7}},
        {10 , {"NextGen Digital faces a decline in user engagement, impacting its stock.", -3.8}},
        {11 , {"CyberLink Industries secures a major contract with a government agency.", 7.4}},
        {12 , {"CrystalPeak Technologies reports a significant increase in sales.", 8.1}},
        {13 , {"RedFox Ventures launches a new tech incubator program.", 5.9}},
        {14 , {"Vanguard Electronics faces a product recall, affecting its reputation.", -6.4}},
        {15 , {"SilverEdge Networks expands its cybersecurity offerings.", 4.5}},
        {16 , {"BlueWave Global partners with influencers to boost brand visibility.", 9.3}},
        {17 , {"Nimbus Enterprises reports a decline in profits due to increased competition.", -5.1}},
        {18 , {"Phoenix Solutions invests in renewable energy projects.", 7.8}},
        {19 , {"MegaByte Corporation announces a new cloud service, enhancing its portfolio.", 6.6}},
        {20 , {"Sunrise Innovations receives funding for a new research project.", 5.2}},
        {21 , {"CyberDyne Labs partners with a leading automotive company for robotics.", 8.7}},
        {22 , {"RedStone Technologies faces scrutiny over its environmental practices.", -4.9}},
        {23 , {"Infinite Horizon Ltd. launches a new app that gains traction in the market.", 7.0}},
        {24 , {"QuantumWave Solutions announces a collaboration with a major tech firm.", 6.3}},
        {25 , {"NanoTech Industries reports a successful product launch.", 8.5}},
        {26 , {"GlobeX Digital faces challenges in scaling its operations.", -3.6}},
        {27 , {"ZeroPoint Ventures invests in AI startups, diversifying its portfolio.", 5.4}},
        {28 , {"CyberSage Enterprises enhances its product offerings to combat new threats.", 7.1}},
        {29 , {"FusionEdge Systems reports a record number of new contracts.", 10.0}},
        {30 , {"TechnoCore Inc. faces a lawsuit over patent infringement.", -5.5}},
        {1 , {"GlobalSoft Ltd. announces a new data privacy initiative.", 6.8}},
        {2 , {"EcoFuture Solutions wins an award for its sustainability efforts.", 8.4}},
        {3 , {"GreenWave Systems expands its operations internationally.", 7.6}},
        {4 , {"AlphaTech Corp. faces a decline in market share due to competition.", -4.2}},
        {5 , {"MicroData Co. announces a new partnership with a tech giant.", 9.1}},
        {6 , {"PrimeCore Technologies reports a significant increase in user adoption.", 8.3}},
        {7 , {"QuantumSoft Enterprises faces delays in product rollout.", -3.4}},
        {8 , {"XenonX Labs secures additional funding for research.", 10.5}},
        {9 , {"SkyNet Innovations launches a new marketing campaign.", 6.9}},
        {10 , {"NextGen Digital reports a decline in revenue.", -5.3}},
        {11 , {"CyberLink Industries enhances its cybersecurity measures.", 7.0}},
        {12 , {"CrystalPeak Technologies faces a drop in stock due to poor earnings.", -6.1}},
        {13 , {"RedFox Ventures announces a new venture into healthcare technology.", 5.8}},
        {14 , {"Vanguard Electronics launches a new line of smart devices.", 8.6}},
        {15 , {"SilverEdge Networks reports a successful quarter.", 7.4}},
        {16 , {"BlueWave Global partners with educational institutions.", 6.2}},
        {17 , {"Nimbus Enterprises faces challenges in its supply chain.", -4.7}},
        {18 , {"Phoenix Solutions announces a new product that enhances productivity.", 9.8}},
        {19 , {"MegaByte Corporation invests in AI research.", 5.5}},
        {20 , {"Sunrise Innovations partners with a leading tech firm for a new project.", 6.4}},
        {21 , {"CyberDyne Labs faces increased competition in the robotics sector.", -3.9}},
        {22 , {"RedStone Technologies announces a new sustainability initiative.", 7.2}},
        {23 , {"Infinite Horizon Ltd. reports a significant increase in customer satisfaction.", 8.1}},
        {24 , {"QuantumWave Solutions launches a new product that gains market attention.", 9.4}},
        {25 , {"NanoTech Industries faces regulatory challenges.", -5.0}},
        {26 , {"GlobeX Digital expands its reach into new markets.", 6.5}},
        {27 , {"ZeroPoint Ventures announces a new partnership with a leading firm.", 5.3}},
        {28 , {"CyberSage Enterprises enhances its threat detection capabilities.", 7.6}},
        {29 , {"FusionEdge Systems reports a successful quarter with record sales.", 10.1}},
        {30 , {"TechnoCore Inc. faces backlash over its data handling practices.", -4.8}},
        {1 , {"GlobalSoft Ltd. announces a new product that addresses user concerns.", 6.7}},
        {2 , {"EcoFuture Solutions partners with NGOs for community projects.", 8.0}},
        {3 , {"GreenWave Systems reports a successful product launch.", 7.9}},
        {4 , {"AlphaTech Corp. faces a decline in stock due to market volatility.", -5.4}},
        {5 , {"MicroData Co. announces a new data analytics service.", 9.2}},
        {6 , {"PrimeCore Technologies expands its global footprint.", 8.5}},
        {7 , {"QuantumSoft Enterprises faces challenges in meeting demand.", -3.7}},
        {8 , {"XenonX Labs secures a major contract with a pharmaceutical company.", 10.4}},
        {9 , {"SkyNet Innovations launches a new AI-driven product.", 6.8}},
        {10 , {"NextGen Digital faces criticism over its advertising practices.", -4.1}},
        {11 , {"CyberLink Industries enhances its customer support services.", 7.3}},
        {12 , {"CrystalPeak Technologies reports a decline in sales.", -5.6}},
        {13 , {"RedFox Ventures invests in renewable energy startups.", 5.9}},
        {14 , {"Vanguard Electronics announces a new partnership with a tech giant.", 8.2}},
        {15 , {"SilverEdge Networks faces a data breach.", -6.3}},
        {16 , {"BlueWave Global reports a significant increase in user engagement.", 11.1}},
        {17 , {"Nimbus Enterprises announces a new strategic direction.", 7.5}},
        {18 , {"Phoenix Solutions invests in employee training programs.", 6.0}},
        {19 , {"MegaByte Corporation faces challenges in its product development.", -4.4}},
        {20 , {"Sunrise Innovations receives recognition for its innovative solutions.", 5.8}},
        {21 , {"CyberDyne Labs partners with universities for research.", 9.6}},
        {22 , {"RedStone Technologies faces scrutiny over its labor practices.", -3.8}},
        {23 , {"Infinite Horizon Ltd. launches a new marketing campaign.", 7.4}},
        {24 , {"QuantumWave Solutions announces a new funding round.", 6.9}},
        {25 , {"NanoTech Industries reports a successful collaboration with a major firm.", 8.3}},
        {26 , {"GlobeX Digital faces challenges in maintaining its market position.", -4.2}},
        {27 , {"ZeroPoint Ventures announces a new initiative to support startups.", 5.6}},
        {28 , {"CyberSage Enterprises enhances its cybersecurity offerings.", 7.8}},
        {29 , {"FusionEdge Systems reports a significant increase in client acquisitions.", 10.2}},
        {30, {"TechnoCore Inc. partners with a leading university for AI research.", 9}}, // Positive news, +9% increase
        {1, {"GlobalSoft Ltd. faces a lawsuit over misleading advertising.", -7}}, // Negative news, -7% decrease
        {2, {"EcoFuture Solutions launches a new solar panel technology.", 11}}, // Positive news, +11% increase
        {3, {"GreenWave Systems reports a successful electric vehicle launch.", 15}}, // Positive news, +15% increase
        {4, {"AlphaTech Corp. faces backlash over environmental concerns.", -10}}, // Negative news, -10% decrease
        {5, {"MicroData Co. announces a new data privacy initiative.", 8}}, // Positive news, +8% increase
        {6, {"PrimeCore Technologies suffers a major data breach.", -12}}, // Negative news, -12% decrease
        {7, {"QuantumSoft Enterprises secures a government contract for cybersecurity.", 14}}, // Positive news, +14% increase
        {8, {"XenonX Labs faces regulatory scrutiny over its new drug.", -5}}, // Negative news, -5% decrease
        {10, {"NextGen Digital expands its services to international markets.", 10}}, // Positive news, +10% increase
        {11, {"CyberLink Industries reports a decline in user satisfaction.", -9}}, // Negative news, -9% decrease
        {12, {"CrystalPeak Technologies launches a new VR gaming platform.", 13}}, // Positive news, +13% increase
        {13, {"RedFox Ventures announces a merger with a tech startup.", 7}}, // Positive news, +7% increase
        {14, {"Vanguard Electronics faces a product recall due to safety issues.", -15}}, // Negative news, -15% decrease
        {15, {"SilverEdge Networks reports record profits in Q2.", 20}}, // Positive news, +20% increase
        {16, {"BlueWave Global enters the blockchain technology sector.", 18}}, // Positive news, +18% increase
        {17, {"Nimbus Enterprises faces a lawsuit over patent infringement.", -10}}, // Negative news, -10% decrease
        {18, {"Phoenix Solutions announces a partnership with a major retailer.", 12}}, // Positive news, +12% increase
        {19, {"MegaByte Corporation struggles with outdated software systems.", -8}}, // Negative news, -8% decrease
        {20, {"Sunrise Innovations receives funding for a new research project.", 9}}, // Positive news, +9% increase
        {21, {"CyberDyne Labs develops a new robotic assistant for homes.", 16}}, // Positive news, +16% increase
        {22, {"RedStone Technologies reports significant layoffs due to restructuring.", -11}}, // Negative news, -11% decrease
        {23, {"Infinite Horizon Ltd. launches a new app that gains popularity.", 10}}, // Positive news, +10% increase
        {24, {"QuantumWave Solutions faces delays in product delivery.", -4}}, // Negative news, -4% decrease
        {25, {"NanoTech Industries announces a breakthrough in nanotechnology.", 15}}, // Positive news, +15% increase
        {26, {"GlobeX Digital faces stiff competition in the cloud storage market.", -6}}, // Negative news, -6% decrease
        {27, {"ZeroPoint Ventures invests in renewable energy startups.", 8}}, // Positive news, +8% increase
        {28, {"CyberSage Enterprises reports a surge in demand for its services.", 14}}, // Positive news, +14% increase
        {29, {"FusionEdge Systems announces a new partnership with a leading automotive company.", 5}}, // Positive news, +5% increase
        {30, {"TechnoCore Inc. faces criticism over its labor practices.", -5}}, // Negative news, -5% decrease

};


QList<QPair< double ,QPair< double ,QPair<int ,QString>>>> loans ;

QList<QPair<QString, float>> nonBorderingCountriesPositiveScenarios = {
    {"Humanitarian aid donation", 12},                     // Humanitarian aid donated by one country to another, not dependent on borders.
    {"Cultural exchange program", 7},                       // Cultural exchanges between countries not necessarily sharing a border.
    {"Military alliance", 15},                              // Formation of a military alliance that may include countries from different regions.
    {"Diplomatic visit", 5},                                // Diplomatic visit unrelated to geographical proximity.
    {"Joint space exploration mission", 13},                // Cooperation in space exploration projects between countries, no borders involved.
    {"Economic partnership", 14},                           // Economic partnership established between non-bordering countries.
    {"Official apology for past wrongs", 8},                // Formal apology issued by one country to another, not necessarily related to border issues.
    {"Foreign direct investment (FDI) in infrastructure", 9}, // Investment in infrastructure, regardless of shared borders.
    {"Diplomatic protest resolution", 6},                   // Resolution of diplomatic protest between two countries, not linked to borders.
    {"International peacekeeping mission cooperation", 14}, // Cooperation in international peacekeeping missions.
    {"Bilateral summit agreement", 11},                     // Agreement reached at a bilateral summit between two non-bordering countries.
    {"High-level state visit", 8},                          // High-level state visits between two countries that don't share a border.
    {"Joint disaster relief operation", 9},                 // Disaster relief efforts between countries not geographically close to each other.
    {"Embassy reopening after suspension", 5},              // Embassy reopening after suspension, unrelated to borders.
    {"Peace treaty negotiation", 16},                       // Negotiation and signing of a peace treaty between non-bordering countries.
    {"UN peacekeeping force deployment", 13},               // Deployment of a UN peacekeeping force between countries, no borders involved.
    {"Leadership change with improved relations", 6},       // Improvement in relations after a leadership change, regardless of borders.
    {"Public support for another country's leaders", 5},    // Public support for foreign leaders not linked to geographic proximity.
    {"Joint research and development in technology", 9},    // Collaboration on R&D projects in technology.
    {"Scientific exchange program", 7},                     // Exchange of scientific knowledge and research.
    {"Mutual disarmament agreement", 13},                   // Agreement between two countries to disarm, not related to borders.
    {"Bilateral defense pact", 14},                         // A defense pact between two countries, regardless of their geographic proximity.
    {"Shared development aid to another country", 8},       // Providing shared development aid to a third country.
    {"Formation of a new regional political alliance", 9},  // Formation of a political alliance among countries from different regions.
    {"Trade tariff reductions", 6},                         // Reduction of trade tariffs that enhance bilateral trade, no borders involved.
    {"Support for democracy movements", 5},                 // Support for democracy movements abroad, not tied to shared borders.
    {"Diplomatic communication channel enhancement", 5},   // Improving diplomatic communication between countries.
    {"Economic assistance to a third country", 7},          // Providing economic assistance to another country, regardless of borders.
    {"Joint investment in education programs", 6},          // Investment in education programs to enhance international cooperation.
    {"International diplomatic partnership", 8},           // Partnerships formed between countries globally, not dependent on borders.
    {"Security cooperation treaty", 7},                     // Treaty formed for security cooperation without a geographical emphasis.
    {"Nuclear disarmament treaty support", 14},             // Support for nuclear disarmament between non-bordering countries.
    {"Trade dispute resolution", 4},                        // Resolution of trade disputes between two countries.
    {"High-ranking official state visit", 7},               // State visits that are not bound by proximity.
    {"Exploring bilateral trade in new sectors", 6},        // Exploring new trade sectors for cooperation between countries.
    {"Participation in multilateral treaties", 5},          // Participation in treaties between multiple countries not tied to borders.
    {"Supporting global economic initiatives", 6},          // Supporting global economic projects and initiatives.
    {"Energy cooperation agreement", 12},                   // Agreement for cooperation in energy projects, not dependent on borders.
    {"Recognition of a new government", 6},                 // Recognition of a new government, regardless of borders.
    {"New diplomatic envoy appointed", 5},                  // Appointment of a diplomatic envoy between countries.
    {"Hosting a visiting dignitary", 6},                    // Hosting visiting dignitaries from other countries.
    {"Bilateral military exchange program", 7},             // Military exchange programs between non-bordering countries.
    {"Hosting an international conference", 7},             // Hosting an international conference unrelated to borders.
    {"Shared technological innovation agreement", 9},       // Agreement on sharing technological innovations.
    {"Increase in cultural tourism", 5},                    // Increase in cultural tourism, not linked to borders.
    {"Economic summit participation", 6},                   // Participation in an international economic summit.
    {"Diplomatic visit by multiple heads of state", 7},     // Multinational diplomatic visits, not border-dependent.
    {"Increased diplomatic personnel exchange", 5},         // Increase in diplomatic personnel exchanges across countries.
    {"Formal diplomatic apology", 7},                       // Formal apologies exchanged between countries, unrelated to borders.
    {"Cultural and educational outreach program", 5}        // Cultural and educational programs not tied to geographical borders.
};

QList<QPair<QString, float>> borderingCountriesPositiveScenarios = {
    {"Non-aggression pact", 10},                          // Agreement between neighboring countries to avoid military conflict.
    {"Trade agreement", 8},                                // Trade agreement that involves cross-border commerce.
    {"Sharing intelligence on terrorism", 10},             // Cooperation between neighboring countries on counter-terrorism intelligence.
    {"Joint military exercise", 12},                       // Military exercises between neighboring countries to enhance defense cooperation.
    {"Refugee assistance", 9},                             // Joint efforts to provide aid to refugees crossing borders.
    {"Joint infrastructure project", 10},                  // Collaborative infrastructure projects between neighboring countries.
    {"Agreement on shared water resources", 8},            // Agreements regarding shared rivers, lakes, or other water resources.
    {"Cross-border infrastructure project", 11},           // Infrastructure development projects along shared borders.
    {"Cooperative climate change policies", 10},           // Joint initiatives to tackle climate change in shared border regions.
    {"Joint military operation", 10},                      // Military operations involving neighboring countries, such as border security operations.
    {"Bilateral defense pact", 14},                        // Agreement between neighboring countries on mutual defense.
    {"Cooperation on maritime security", 7},               // Cooperation on maritime security in shared border regions like coastal zones.
    {"Joint anti-terrorism campaign", 9},                  // Joint efforts between neighboring countries to combat terrorism.
    {"Sharing border security information", 8},            // Exchange of border security data between neighboring countries.
    {"Bilateral investment in technological infrastructure", 9}, // Investment in cross-border technological initiatives.
    {"Joint peacekeeping mission", 8},                     // Collaborative peacekeeping efforts in a shared region.
    {"Peace talks with insurgent groups", 13},              // Neighboring countries working together to mediate peace talks in a conflict zone.
    {"Cessation of arms embargo", 9},                      // Lifting of arms embargo between neighboring countries, fostering military cooperation.
    {"Joint cyber defense agreement", 10},                 // Agreement between neighboring countries to jointly protect against cyber threats.
    {"Recognition of a new government", 6},                // A neighboring country recognizes a new government in a border region.
    {"Peace treaty signing", 16},                          // Formal signing of a peace treaty between neighboring countries after resolving border disputes.
    {"Sharing border security information", 8},            // Collaborative sharing of border security data between neighboring countries.
    {"Diplomatic visit by multiple heads of state", 7},    // High-level diplomatic visits between neighboring states to enhance bilateral relations.
};

QList<QPair<QString, float>> borderingCountriesNegativeScenarios = {
    {"Border skirmish", -10},                           // Direct military conflict along the border.
    {"Military intervention in a neighboring country", -15}, // Military action in a bordering country.
    {"Military escalation in a shared region", -15},        // Escalating conflict in a region that both countries share.
    {"Violent border clash", -10},                         // Violent clash at the border between two neighboring countries.
    {"Military deployment near the border", -8},           // Troop build-up close to a border, creating tensions.
    {"Escalating border disputes", -10},                   // Ongoing territorial disputes between bordering nations.
    {"Cross-border military confrontation", -15},          // Military engagement crossing borders.
    {"Unilateral border crossing enforcement", -11},       // One country unilaterally enforces its own rules at a shared border.
    {"Military aggression in a neutral zone", -15},        // Aggression or military action in a neutral border zone.
    {"Illegal territorial claim", -18},                    // Claiming territory that lies within another nation's border.
    {"Disputed maritime territory standoff", -10},         // Dispute over maritime borders between neighboring countries.
    {"Illegal annexation of disputed land", -18},          // Annexing land that is disputed and shared between bordering countries.
    {"Hostile naval encounter", -9},                       // Military naval confrontation in shared maritime borders.
    {"Military aggression in a shared region", -15},       // Military conflict in a region that is jointly controlled or disputed.
    {"Suspension of trade agreements", -9},                // Trade agreements impacted by issues along the border.
    {"Suspension of international agreements", -10},       // Diplomatic agreements impacting relations between neighboring nations.
    {"Military drills in disputed territory", -10},        // Military exercises conducted in areas where territorial disputes exist.
    {"Suspension of peace agreement", -13},                // Suspension of an agreement meant to ensure peace along a border.
    {"Accusation of state-sponsored terrorism", -12},       // Terrorist activity emanating from a shared border region.
    {"Diplomatic recall", -10},                            // Recall of diplomats due to tensions along the border.
    {"Withdrawal from regional military alliance", -7},    // Withdrawal from an alliance or agreement that affects border security.
    {"Diplomatic protest", -6},                            // Formal protest over border issues or territorial rights.
    {"Cultural embargo", -7},                              // A cultural embargo due to border disputes or conflict.
    {"Imposition of arms embargo", -10},                   // An arms embargo imposed due to security concerns at the border.
    {"Closure of military base", -9},                      // Military bases near the border being closed due to rising tensions.
    {"Increased arms race tension", -12},                  // The growing arms race along a shared border due to military threats.
    {"Unilateral action in disputed waters", -12},         // One country taking unilateral action in disputed waters, causing conflict.
    {"Suspension of foreign military aid", -10},           // Foreign military aid suspended due to security concerns near the border.
    {"Violation of diplomatic protocols", -6},             // Diplomatic violations stemming from border-related tensions.
    {"Opposition to foreign peace initiatives", -8},        // Opposing peace proposals regarding shared border regions.
    {"Unilateral economic sanctions", -14},                // Economic sanctions imposed due to border issues or violations.
    {"Severance of diplomatic ties", -20},                 // Complete breakdown of diplomatic relations due to border conflicts.
    {"Public condemnation of foreign leader", -10},        // Condemnation of foreign leadership involved in border disputes.
    {"Accusations of espionage", -10},                     // Accusations tied to border security or military actions.
    {"Bilateral tourism ban", -5},                         // Ban on tourism as a result of heightened tensions at the border.
    {"Government-backed human rights violations", -11},    // Human rights violations in border areas causing diplomatic fallout.
    {"Mass deportation of nationals", -10},                // Deportations along the border in response to political or military tensions.
    {"Imposing travel restrictions", -6},                  // Restrictions on travel due to security concerns along the border.
    {"Government corruption scandal affecting relations", -14}, // Corruption related to border security or cross-border issues.
    {"Imposing or receiving diplomatic sanctions", -14},   // Sanctions related to border conflicts.
    {"Imposing travel bans", -6},                          // Travel bans linked to rising border tensions.
    {"Secret military operation exposure", -12},           // Exposure of covert military operations near the border.
    {"Suspension of diplomatic relations", -18},           // Suspension of diplomatic ties due to conflict along the border.
    {"International condemnation of military action", -10}, // Military actions near or across a border causing international backlash.
    {"Hostile border encounter", -9}                       // Any military or hostile encounter that takes place on the border.
};


QList<QPair<QString, float>> nonBorderingCountriesNegativeScenarios = {
    {"Economic sanctions imposed", -15},                     // Imposition of sanctions that are not related to border issues.
    {"Cyber attack accusation", -12},                         // Accusations of cyber attacks affecting diplomatic ties.
    {"Breaking of diplomatic ties", -20},                     // Diplomatic ties being broken over non-border-related issues.
    {"Public condemnation of a regime", -12},                 // Condemnation of a foreign regime for political reasons, unrelated to borders.
    {"Suspension of peace agreement", -13},                   // Suspension of peace agreements unrelated to direct border conflicts.
    {"Unilateral action in disputed waters", -12},            // Disputes over waters not directly tied to a shared land border.
    {"Violent protest against foreign policy", -6},            // Protests related to foreign policy decisions or actions, not border-related.
    {"Opposition to UN resolution", -5},                      // Disagreement with a UN resolution, not tied to borders.
    {"Diplomatic protest", -6},                               // A formal protest unrelated to direct border issues.
    {"Opposing a rival's UN Security Council bid", -8},        // Opposing another country's bid in the UN, not connected to border conflict.
    {"Accusations of espionage", -10},                        // Espionage accusations not directly related to borders.
    {"Cultural embargo", -7},                                 // Cultural embargo imposed over issues not connected to borders.
    {"Breaking of long-standing partnership", -9},             // Diplomatic fallout leading to breaking long-standing partnerships.
    {"Diplomatic boycott of an international event", -9},     // Boycott of international events due to political reasons.
    {"Support for sanctions against a third country", -6},     // Supporting sanctions on a third country, not directly linked to borders.
    {"Increased diplomatic tension", -7},                     // Growing diplomatic tensions unrelated to geographical proximity.
    {"Opposition to economic partnership proposal", -5},       // Disagreement with economic proposals not tied to borders.
    {"Opposing arms trade embargo", -8},                      // Disagreement over arms trade restrictions or embargoes unrelated to borders.
    {"Cutting off military ties", -8},                        // Military ties being severed, not due to border-related actions.
    {"Imposing or receiving diplomatic sanctions", -14},      // Sanctions imposed or received for political reasons unrelated to borders.
    {"Withdrawal from regional military alliance", -7},       // Withdrawal from a multilateral military alliance.
    {"Foreign debt forgiveness rejection", -9},               // Rejection of debt forgiveness impacting diplomatic relations.
    {"Government corruption scandal affecting relations", -14}, // Corruption scandal hurting bilateral relations.
    {"Suspension of foreign military aid", -10},              // Suspension of military aid unrelated to direct border concerns.
    {"Support for opposing political factions", -7},          // Support for opposing political groups or regimes in other countries.
    {"Embassy closure", -8},                                  // Closure of embassies, not tied to border conflict.
    {"Imposition of travel bans", -6},                        // Travel restrictions unrelated to border disputes.
    {"Opposition to regional peace talks", -5},                // Opposition to peace talks not directly connected to borders.
    {"Public criticism of foreign leader", -10},               // Public criticism of a foreign leader due to non-border-related policies.
    {"Diplomatic recall", -10},                               // Diplomatic staff being recalled due to international issues not tied to borders.
    {"Accusation of state-sponsored terrorism", -12},          // Terrorism-related accusations unrelated to border areas.
    {"Economic embargo imposed", -15},                        // Economic embargo not related to a border conflict.
    {"Military aggression in a neutral zone", -15},           // Aggression in a neutral zone that is not part of a shared border.
    {"Suspension of trade agreements", -9},                   // Suspension of trade agreements due to political reasons not tied to borders.
    {"High-ranking official assassination", -18},             // Political assassination causing diplomatic fallout.
    {"Escalating border disputes", -10},                      // Escalating border disputes (listed here mistakenly, as it's border-related).
    {"Unilateral withdrawal from a trade pact", -6},          // Withdrawal from a trade pact not related to border issues.
    {"Suspension of diplomatic relations", -18},              // Suspension of diplomatic relations unrelated to borders.
    {"Trade war declaration", -12},                           // Declaration of a trade war not linked to geographical proximity.
    {"Disputed maritime territory standoff", -10},            // Maritime standoff over disputed waters, not directly tied to land borders.
    {"Unilateral economic sanctions", -14},                   // Economic sanctions imposed unilaterally due to political differences.
    {"Trade tariff increases", -7},                           // Increases in tariffs affecting trade relations.
    {"Closure of military base", -9},                         // Closure of a military base unrelated to border tensions.
    {"Military aggression in a shared region", -15},          // Military aggression in a region not necessarily a shared border.
    {"Increased arms race tension", -12},                     // Growing arms race tension not connected to specific borders.
    {"International condemnation of military action", -10},   // International condemnation over military action unrelated to borders.
    {"Government-backed human rights violations", -11},       // Human rights violations leading to diplomatic fallout, not tied to borders.
    {"Diplomatic incident at international summit", -8},      // Diplomatic incident occurring during a summit, unrelated to borders.
    {"Hostile naval encounter", -9},                          // Naval encounter in international waters, not tied to shared borders.
    {"Mass deportation of nationals", -10},                   // Deportation of nationals affecting international relations.
    {"Severance of diplomatic ties", -20},                    // Severance of diplomatic ties due to non-border-related issues.
    {"Bilateral tourism ban", -5},                            // Ban on tourism due to diplomatic or political reasons.
    {"Imposition of arms embargo", -10},                      // Arms embargo imposed for non-border-related issues.
    {"Withdrawal from multilateral treaties", -9},            // Withdrawal from treaties affecting international relations.
    {"Recognition of a rogue state", -10},                    // Recognizing a country as a rogue state, leading to diplomatic fallout.
    {"Trade restrictions imposed", -7},                       // Imposition of trade restrictions due to political differences.
    {"Military aid suspension", -10},                         // Suspension of military aid for political reasons.
    {"Closure of diplomatic mission", -10},                   // Closure of diplomatic missions due to political conflicts.
    {"Secret military operation exposure", -12},              // Exposure of a secret military operation that impacts relations.
    {"Cross-border military confrontation", -15},             // Military confrontation crossing borders (listed earlier, as it's border-related).
    {"Suspension of international agreements", -10},          // Suspension of multilateral agreements due to political reasons.
    {"Trade dispute escalation", -7},                         // Escalating trade disputes not linked to borders.
    {"Military drills in disputed territory", -10},           // Military drills in disputed territories, unrelated to direct borders.
    {"Unilateral border crossing enforcement", -11},          // Border enforcement issues (listed earlier as border-related).
    {"Illegal territorial claim", -18},                       // Illegal claim over territory not directly affecting borders.
    {"Imposition of travel restrictions", -6},                // Travel restrictions unrelated to border disputes.
    {"Condemnation of political regime", -10},                // Condemnation of political regimes without direct border issues.
    {"Violation of diplomatic protocols", -6},                // Violations of diplomacy not related to borders.
    {"Overflight restrictions", -7},                          // Restrictions on airspace, not linked to border disputes.
    {"Support for hostile trade policy", -8},                 // Supporting hostile trade policies against other countries.
    {"Condemnation of foreign alliances", -6},                // Condemnation of foreign alliances for political reasons.
    {"Opposition to foreign peace initiatives", -8}           // Opposition to international peace efforts, unrelated to borders.
};

QList<QPair<QString, float>> neighboringCountriesDiplomaticStatus = {
    {"India", 30},      // Diplomatic relations with India are tense due to historical issues, the Kashmir conflict, and military skirmishes.
    {"Afghanistan", 55}, // Relations fluctuate due to border security issues, political instability in Afghanistan, and the Taliban government.
    {"China", 85},       // Strong diplomatic, economic, and military ties with China, especially in infrastructure, trade, and regional alignment.
    {"Iran", 70}         // Generally cooperative, but there are tensions over border security, sectarian concerns, and regional influence.
};


QList<QPair<QString, float>> countriesExcludingNeighborsDiplomaticStatus = {
    {"United States", 65},       // Generally cooperative but tense at times due to differing regional policies, such as in Afghanistan.
    {"United Kingdom", 80},      // Strong historical ties, with robust trade, diplomatic, and defense relations.
    {"Russia", 50},              // Improving relations, but still marred by historical tensions, regional policy differences, and competition.
    {"Germany", 70},             // Diplomatic and economic ties are strong, though Pakistan is less involved in EU political matters.
    {"France", 60},              // Strong trade ties, but there are occasional disagreements on security and human rights issues.
    {"Japan", 75},               // Positive diplomatic relations, particularly in trade and development assistance.
    {"Brazil", 55},              // Moderate relations, mostly in the form of trade and diplomacy, with limited cooperation beyond that.
    {"Canada", 70},              // Generally friendly, with a strong Pakistani diaspora, though some tensions over immigration policies.
    {"Turkey", 80},              // Close diplomatic ties, especially in defense, trade, and cultural exchange.
    {"Saudi Arabia", 75},        // Strong economic, trade, and military relations, though occasional differences over regional policies.
    {"Egypt", 65},               // Generally positive relations, with cooperation in trade, military, and cultural sectors.
    {"South Africa", 60},        // Relations are friendly, focused on trade and development cooperation, though not very strong.
    {"Australia", 70},           // Strong diplomatic and trade relations, with some differences over issues such as Afghanistan.
    {"New Zealand", 65},         // Cooperative relations in trade and security, though limited in scope compared to larger nations.
    {"Mexico", 55},              // Diplomatic ties exist, but trade and cultural relations are not as robust as with some other countries.
    {"Argentina", 60},           // Relations are friendly, with trade and diplomatic cooperation, but not deeply strategic.
    {"Chile", 55},               // Diplomatic and trade relations are neutral but not particularly deep.
    {"Norway", 65},              // Stable relations, especially on human rights and development cooperation.
    {"Sweden", 70},              // Strong human rights and development cooperation, with good diplomatic relations.
    {"Denmark", 70},             // Relations are generally good, with trade and human rights diplomacy playing a key role.
    {"Finland", 70},             // Positive diplomatic relations, with a focus on education, development, and human rights.
    {"Poland", 60},              // Growing relations in trade and culture, but not as extensive as with other European nations.
    {"Italy", 65},               // Diplomatic and economic relations are friendly, though not particularly deep.
    {"Spain", 70},               // Positive diplomatic and trade relations, with some cooperation in regional matters.
    {"Belgium", 60},             // Good diplomatic ties, primarily in the trade and development sectors.
    {"Netherlands", 65},         // Strong trade relations and some cooperation on humanitarian issues.
    {"Switzerland", 60},         // Neutral, generally positive diplomatic relations, with focus on trade and financial services.
    {"South Korea", 60},         // Growing relations in trade and technology, but limited political or military cooperation.
    {"Singapore", 70},           // Strong economic and trade ties, especially in areas like logistics and infrastructure.
    {"Malaysia", 75},            // Strong ties, particularly in defense and economic cooperation.
    {"Indonesia", 75},           // Friendly relations, with significant trade, and common interests in regional security.
    {"Philippines", 55},         // Generally neutral, with some cooperation in areas like trade and regional security.
    {"Thailand", 60},            // Moderate relations, with cooperation in trade, tourism, and regional matters.
    {"Vietnam", 55},             // Relations are neutral, with growing trade and diplomatic ties.
    {"Bangladesh", 60},          // Diplomatic relations are stable, with occasional tension due to historical issues, but cooperation on trade.
    {"Sri Lanka", 65},           // Friendly ties, especially in trade and defense, though not deeply strategic.
    {"Nepal", 60},               // Neutral relations, with some cooperation in trade and regional diplomacy.
    {"Myanmar", 50},             // Relations have been inconsistent, with concerns over military dictatorship and human rights issues.
    {"Maldives", 70},            // Good diplomatic relations, with cooperation in trade, tourism, and defense.
    {"Kuwait", 70},              // Stable relations, mainly through the Pakistani diaspora and economic cooperation.
    {"Qatar", 75},               // Strong ties, particularly in trade, defense, and energy sectors.
    {"Jordan", 60},              // Diplomatic relations are friendly, with cooperation in defense and trade.
    {"Lebanon", 60},             // Generally friendly ties, with some diplomatic cooperation in regional matters.
    {"Iraq", 60},                // Moderate relations, with some trade and security cooperation but occasional tensions.
    {"United Arab Emirates", 80}, // Very strong relations in trade, investment, and defense.
    {"Oman", 75},                // Friendly and stable ties, with significant trade and defense cooperation.
    {"Bahrain", 65},             // Diplomatic and trade relations are strong, particularly due to the Pakistani diaspora.
    {"Yemen", 50},               // Relations are complicated by the ongoing conflict in Yemen and regional politics.
    {"Israel", 30},               // No diplomatic relations; Pakistan does not recognize Israel.
    {"North Korea", 20},         // Diplomatic relations are almost non-existent, with minimal contact, though both share a position against the West.
    {"Mongolia", 45},            // Relations are neutral, with little diplomatic or trade exchange, but growing interest in regional cooperation.
    {"Algeria", 55},             // Relations are generally friendly but not deeply strategic, with some cooperation in defense and trade.
    {"Tunisia", 55},             // Diplomatic relations are stable, with some trade and cultural exchanges.
    {"Libya", 50},               // Relations are generally neutral, with limited interaction due to internal instability in Libya.
    {"Sudan", 60},               // Moderate relations, with some cooperation in trade, humanitarian aid, and defense.
    {"Ethiopia", 55},            // Relations are neutral, with occasional engagement over regional security and trade.
    {"Kenya", 60},               // Good diplomatic ties, particularly in trade and development cooperation.
    {"Nigeria", 55},             // Relations are cordial, focused on trade and regional security cooperation.
    {"Ghana", 60},               // Positive diplomatic relations, with some engagement in trade and development.
    {"Zimbabwe", 45},            // Relations are moderate, mainly in trade but not very deep.
    {"Mozambique", 50},          // Relations are neutral, with some diplomatic contact in the context of development.
    {"Angola", 55},              // Relations are cordial but largely based on trade with limited strategic depth.
    {"Botswana", 50},            // Relations are neutral, with occasional exchanges and cooperation on development issues.
    {"Namibia", 50},             // Diplomatic ties are neutral, with limited engagement in trade or cultural cooperation.
    {"Zambia", 55},              // Relations are relatively friendly but mainly focused on trade and development cooperation.
    {"Malawi", 50},              // Relations are cordial but relatively shallow, with focus on humanitarian and development issues.
    {"Tanzania", 55},            // Relations are friendly but not extensive, with some engagement in trade and development.
    {"Seychelles", 50},          // Diplomatic relations are neutral, with limited engagement but potential for tourism and trade.
    {"Mauritius", 60},           // Good diplomatic relations, with cooperation in trade, investment, and tourism.
    {"Reunion (France)", 60},    // Diplomatic ties are generally positive, though not particularly deep due to its status as a French overseas territory.
    {"Comoros", 45},             // Relations are cordial but not very deep, with limited engagement in regional issues.
    {"Madagascar", 50}           // Relations are neutral, with some exchange in trade and development cooperation.
};

struct Scenario {
    QString headline;
    float change;
};

QList<Scenario> positiveScenarios;

void addPositiveScenarios() {
    positiveScenarios.append({"PM's approval rating increases", 1.2});
    positiveScenarios.append({"Government wins a crucial by-election", 1.5});
    positiveScenarios.append({"Government announces a new economic policy", 1.8});
    positiveScenarios.append({"Government passes a key legislation", 1.2});
    positiveScenarios.append({"Government forms a new alliance", 1.1});
    positiveScenarios.append({"Government announces a new infrastructure project", 1.9});
    positiveScenarios.append({"Government launches a new energy policy", 1.4});
    positiveScenarios.append({"Government launches a new social welfare program", 1.1});
    positiveScenarios.append({"Government wins a confidence vote", 1.3});
    positiveScenarios.append({"Government announces a new education policy", 1.2});
    positiveScenarios.append({"Government launches a new tourism initiative", 1.1});
    positiveScenarios.append({"Government announces a new agriculture policy", 1.3});
    positiveScenarios.append({"Government launches a new IT initiative", 1.2});
    positiveScenarios.append({"Inflation rate declines", 1.1});
    positiveScenarios.append({"Government announces a new trade policy", 1.2});
    positiveScenarios.append({"Fiscal policy committee formed", 1.1});
    positiveScenarios.append({"Monetary policy committee formed", 1.0});
    positiveScenarios.append({"Government launches a new poverty reduction program", 1.2});
    positiveScenarios.append({"Government announces a new labor policy", 1.1});
    positiveScenarios.append({"Government launches a new entrepreneurship initiative", 1.2});
    positiveScenarios.append({"Government announces a new environmental policy", 1.1});
    positiveScenarios.append({"Government launches a new disaster relief program", 1.2});
    positiveScenarios.append({"Government announces a new foreign policy", 1.1});
    positiveScenarios.append({"Diplomatic relations with a key country improve", 1.3});
    positiveScenarios.append({"Government launches a new defense initiative", 1.2});
    positiveScenarios.append({"Government announces a new national security policy", 1.1});
    positiveScenarios.append({"Government launches a new counter-terrorism initiative", 1.2});
    positiveScenarios.append({"Government announces a new law and order policy", 1.1});
    positiveScenarios.append({"Government launches a new justice initiative", 1.2});
    positiveScenarios.append({"Government announces a new human rights policy", 1.1});
    positiveScenarios.append({"Government launches a new women's empowerment initiative", 1.2});
    positiveScenarios.append({"Government announces a new youth policy", 1.1});
    positiveScenarios.append({"Government launches a new education initiative", 1.2});
    positiveScenarios.append({"Government announces a new healthcare policy", 1.1});
    positiveScenarios.append({"Government launches a new infrastructure project", 1.9});
    positiveScenarios.append({"Infrastructure development accelerates", 1.5});
    positiveScenarios.append({"Government announces a new transportation policy", 1.2});
    positiveScenarios.append({"Transportation infrastructure development accelerates", 1.5});
    positiveScenarios.append({"Government launches a new energy initiative", 1.4});
    positiveScenarios.append({"Government announces a new water policy", 1.2});
    positiveScenarios.append({"Government launches a new agriculture initiative", 1.3});
    positiveScenarios.append({"Government announces a new industry policy", 1.2});
    positiveScenarios.append({"IT sector growth accelerates", 1.5});
    positiveScenarios.append({"Government announces a new tourism policy", 1.2});
    positiveScenarios.append({"Tourism industry growth accelerates", 1.5});
    positiveScenarios.append({"Government launches a new poverty reduction program", 1.2});
    positiveScenarios.append({"Poverty rate declines", 1.1});
    positiveScenarios.append({"Government announces a new labor policy", 1.1});
    positiveScenarios.append({"Labor market conditions improve", 1.2});
    positiveScenarios.append({"Unemployment rate declines", 1.1});
    positiveScenarios.append({"Government launches a new entrepreneurship initiative", 1.2});
    positiveScenarios.append({"Entrepreneurship growth accelerates", 1.5});
    positiveScenarios.append({"Government announces a new environmental policy", 1.1});
    positiveScenarios.append({"Disaster relief efforts improve", 1.1});
    positiveScenarios.append({"Government launches a new defense initiative", 1.2});
    positiveScenarios.append({"Defense spending increases", 1.1});
    positiveScenarios.append({"Government announces a new national security policy", 1.1});
    positiveScenarios.append({"Counter-terrorism efforts improve", 1.1});
    positiveScenarios.append({"Government announces a new law and order policy", 1.1});
    positiveScenarios.append({"Crime rate declines", 1.1});
    positiveScenarios.append({"Government launches a new justice initiative", 1.2});
    positiveScenarios.append({"Justice system reforms accelerate", 1.5});
    positiveScenarios.append({"Government announces a new human rights policy", 1.1});
    positiveScenarios.append({"Government launches a new women's empowerment initiative", 1.2});
    positiveScenarios.append({"Women's empowerment accelerates", 1.5});
}
QList<Scenario> negativeScenarios;

void addNegativeScenarios() {
    negativeScenarios.append({"Cabinet reshuffle", -0.5});
    negativeScenarios.append({"Opposition parties unite against government", -1.1});
    negativeScenarios.append({"PM's health issues", -0.8});
    negativeScenarios.append({"Opposition leader arrested", -1.3});
    negativeScenarios.append({"PM's popularity declines", -0.9});
    negativeScenarios.append({"Protests erupt in major cities", -1.5});
    negativeScenarios.append({"Trade deficit widens", -1.1});
    negativeScenarios.append({"Inflation rate increases", -0.9});
    negativeScenarios.append({"Fiscal deficit widens", -1.2});
    negativeScenarios.append({"Government announces a new tax policy", -0.6});
    negativeScenarios.append({"Interest rates increase", -1.2});
    negativeScenarios.append({"Opposition parties boycott parliament", -1.1});
    negativeScenarios.append({"Healthcare crisis deepens", -1.0});
    negativeScenarios.append({"Security situation deteriorates", -1.4});
    negativeScenarios.append({"Industrial production declines", -1.0});
    negativeScenarios.append({"Unemployment rate increases", -1.0});
    negativeScenarios.append({"Natural disaster strikes", -1.5});
    negativeScenarios.append({"Diplomatic relations with a key country deteriorate", -1.2});
    negativeScenarios.append({"Terrorism incidents increase", -1.4});
    negativeScenarios.append({"Crime rate increases", -1.0});
    negativeScenarios.append({"Human rights abuses reported", -1.2});
    negativeScenarios.append({"Youth unemployment rate increases", -1.0});
    negativeScenarios.append({"Healthcare crisis deepens", -1.0});
    negativeScenarios.append({"Energy crisis deepens", -1.0});
    negativeScenarios.append({"Water scarcity issues worsen", -1.0});
    negativeScenarios.append({"Agricultural production declines", -1.0});
    negativeScenarios.append({"Industrial production declines", -1.0});
    negativeScenarios.append({"Environmental issues worsen", -1.0});
    negativeScenarios.append({"Natural disaster strikes", -1.5});
    negativeScenarios.append({"Diplomatic relations with a key country deteriorate", -1.2});
    negativeScenarios.append({"Terrorism incidents increase", -1.4});
    negativeScenarios.append({"National security concerns worsen", -1.0});
    negativeScenarios.append({"Human rights abuses reported", -1.2});
}
