/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#ifndef __DAVE_ENUM_H__
#define __DAVE_ENUM_H__

typedef enum {
	GPSBaseLocation_East,
	GPSBaseLocation_West,
	GPSBaseLocation_North,
	GPSBaseLocation_South
} GPSBaseLocation;

typedef enum {
	CurrencyType_reserve = 0,
	CurrencyType_audio = 1,
	CurrencyType_video = 2,
	CurrencyType_RMB = 3,
	CurrencyType_USD = 4,
	CurrencyType_GBP = 5,
	CurrencyType_JPY = 6,
	CurrencyType_EUR = 7,
	CurrencyType_AUD = 8,
	CurrencyType_DEM = 9,
	CurrencyType_CHF = 10,
	CurrencyType_FRF = 11,
	CurrencyType_CAD = 12,
	CurrencyType_HKD = 13,
	CurrencyType_ATS = 14,
	CurrencyType_FIM = 15,
	CurrencyType_BEF = 16,
	CurrencyType_NZD = 17,
	CurrencyType_SGD = 18,
	CurrencyType_KRW = 19,
	CurrencyType_IEP = 20,
	CurrencyType_ITL = 21,
	CurrencyType_LUF = 22,
	CurrencyType_NLG = 23,
	CurrencyType_PTE = 24,
	CurrencyType_ESP = 25,
	CurrencyType_IDR = 26,
	CurrencyType_MYR = 27,
	CurrencyType_PHP = 28,
	CurrencyType_SUR = 29,
	CurrencyType_THB = 30,
	CurrencyType_reserve1 = 31,

	CurrencyType_max,
} CurrencyType;

/* http://www.supfree.net/search.asp?id=6073 */

typedef enum {
	CountryCode_reserve = 0,
	CountryCode_Angola = 1,
	CountryCode_Afghanistan = 2,
	CountryCode_Canada_or_USA = 3,
	CountryCode_China = 4,
	CountryCode_Hongkong = 5,
	CountryCode_Albania = 6,
	CountryCode_Algeria = 7,
	CountryCode_Andorra = 8, 
	CountryCode_Anguilla = 9, 
	CountryCode_Antigua_and_Barbuda = 10,
	CountryCode_Argentina = 11,
	CountryCode_Armenia = 12,
	CountryCode_Ascension = 13,
	CountryCode_Australia = 14,
	CountryCode_Austria = 15,
	CountryCode_Azerbaijan = 16, 
	CountryCode_Bahamas = 17,
	CountryCode_Bahrain = 18,
	CountryCode_Bangladesh = 19,
	CountryCode_Barbados = 20,
	CountryCode_Belarus = 21,
	CountryCode_Belgium = 22,
	CountryCode_Belize = 23,
	CountryCode_Benin = 24,
	CountryCode_Bermuda = 25,
	CountryCode_Bolivia = 26,
	CountryCode_Botswana = 27,
	CountryCode_Brazil = 28,
	CountryCode_Brunei = 29,
	CountryCode_Bulgaria = 30,
	CountryCode_Burkina_faso = 31,
	CountryCode_Burma = 32,
	CountryCode_Burundi = 33,
	CountryCode_Cameroon = 34,
	CountryCode_Cayman = 35,
	CountryCode_Central_African = 36,
	CountryCode_Chad = 37,
	CountryCode_Chile = 38,
	CountryCode_Colombia = 39,
	CountryCode_Congo = 40,
	CountryCode_Cook = 41,
	CountryCode_Costa_Rica = 42,
	CountryCode_Cuba = 43,
	CountryCode_Cyprus = 44,
	CountryCode_Czech = 45,
	CountryCode_Denmark = 46,
	CountryCode_Djibouti = 47,
	CountryCode_Dominica = 48,
	CountryCode_Ecuador = 49,
	CountryCode_Egypt = 50,
	CountryCode_Salvador = 51,
	CountryCode_Estonia = 52,
	CountryCode_Ethiopia = 53,
	CountryCode_Fiji = 54,
	CountryCode_Finland = 55,
	CountryCode_France = 56,
	CountryCode_French_Guiana = 57,
	CountryCode_Gabon = 58,
	CountryCode_Gambia = 59,
	CountryCode_Georgia = 60,
	CountryCode_Germany = 61,
	CountryCode_Ghana = 62,
	CountryCode_Gibraltar = 63,
	CountryCode_Greece = 64,
	CountryCode_Grenada = 65,
	CountryCode_Guam = 66,
	CountryCode_Guatemala = 67,
	CountryCode_Guinea = 68,
	CountryCode_Guyana = 69,
	CountryCode_Haiti  = 70, 
	CountryCode_Honduras = 71,
	CountryCode_Hungary = 72,
	CountryCode_Iceland = 73,
	CountryCode_India = 74,
	CountryCode_Indonesia = 75,
	CountryCode_Iran = 76,
	CountryCode_Iraq = 77, 
	CountryCode_Ireland = 78,
	CountryCode_Israel = 79,
	CountryCode_Italy = 80, 
	CountryCode_Ivory_Coast = 81, 
	CountryCode_Jamaica = 82, 
	CountryCode_Japan = 83, 
	CountryCode_Jordan = 84, 
	CountryCode_Cambodia = 85,
	CountryCode_Kazakstan = 86,
	CountryCode_Kenya = 87,
	CountryCode_South_Korea = 88,
	CountryCode_Kuwait = 89,
	CountryCode_Kyrgyzstan	= 90, 
	CountryCode_Laos = 91, 
	CountryCode_Latvia = 92,
	CountryCode_Lebanon = 93, 
	CountryCode_Lesotho = 94, 
	CountryCode_Liberia = 95,
	CountryCode_Libya = 96,
	CountryCode_Liechtenstein = 97, 
	CountryCode_Lithuania = 98, 
	CountryCode_Luxembourg = 99, 
	CountryCode_Macao = 100, 
	CountryCode_Madagascar = 101, 
	CountryCode_Malawi = 102, 
	CountryCode_Malaysia = 103, 
	CountryCode_Maldives = 104,
	CountryCode_Mali = 105, 
	CountryCode_Malta = 106,
	CountryCode_Mariana = 107, 
	CountryCode_Martinique = 108, 
	CountryCode_Mauritius = 109, 
	CountryCode_Mexico = 110, 
	CountryCode_Moldova = 111, 
	CountryCode_Monaco = 112, 
	CountryCode_Mongolia  = 113, 
	CountryCode_Montserrat = 114,
	CountryCode_Morocco = 115, 
	CountryCode_Mozambique = 116, 
	CountryCode_Namibia  = 117, 
	CountryCode_Nauru = 118, 
	CountryCode_Nepal = 119, 
	CountryCode_Netheriands_Antilles = 120, 
	CountryCode_Netherlands = 121, 
	CountryCode_New_Zealand = 122, 
	CountryCode_Nicaragua = 123, 
	CountryCode_Niger = 124,
	CountryCode_Nigeria = 125, 
	CountryCode_North_Korea = 126, 
	CountryCode_Norway = 127, 
	CountryCode_Oman = 128, 
	CountryCode_Pakistan = 129,
	CountryCode_Panama = 130, 
	CountryCode_Papua_New_Cuinea = 131,
	CountryCode_Paraguay = 132, 
	CountryCode_Peru = 133,
	CountryCode_Philippines = 134, 
	CountryCode_Poland = 135, 
	CountryCode_French_Polynesia = 136, 
	CountryCode_Portugal = 137, 
	CountryCode_Puerto_Rico = 138,
	CountryCode_Qatar = 139,
	CountryCode_Reunion = 140, 
	CountryCode_Romania = 141, 
	CountryCode_Russia = 142, 
	CountryCode_Saint_Lueia = 143, 
	CountryCode_Saint_Vincent = 144, 
	CountryCode_Samoa_Eastern = 145, 
	CountryCode_Samoa_Western = 146, 
	CountryCode_San_Marino = 147, 
	CountryCode_Sao_Tome_and_Principe = 148, 
	CountryCode_Saudi_Arabia = 149, 
	CountryCode_Senegal = 150, 
	CountryCode_Seychelles = 151, 
	CountryCode_Sierra_Leone = 152, 
	CountryCode_Singapore = 153,
	CountryCode_Slovakia = 154, 
	CountryCode_Slovenia = 155,
	CountryCode_Solomon = 156, 
	CountryCode_Somali = 157, 
	CountryCode_South_Africa = 158, 
	CountryCode_Spain = 159, 
	CountryCode_Sri_Lanka = 160, 
	CountryCode_St_Lucia = 161, 
	CountryCode_St_Vincent = 162, 
	CountryCode_Sudan = 163, 
	CountryCode_Suriname = 164, 
	CountryCode_Swaziland = 165, 
	CountryCode_Sweden = 166, 
	CountryCode_Switzerland = 167, 
	CountryCode_Syria = 168, 
	CountryCode_Taiwan = 169, 
	CountryCode_Tajikstan = 170,
	CountryCode_Tanzania = 171, 
	CountryCode_Thailand = 172, 
	CountryCode_Togo = 173, 
	CountryCode_Tonga = 174, 
	CountryCode_Trinidad_and_Tobago = 175, 
	CountryCode_Tunisia = 176, 
	CountryCode_Turkey = 177,
	CountryCode_Turkmenistan = 178, 
	CountryCode_Uganda = 179, 
	CountryCode_Ukraine = 180, 
	CountryCode_United_Arab_Emirates = 181, 
	CountryCode_United_Kingdom = 182, 
	CountryCode_Uruguay = 183, 
	CountryCode_Uzbekistan = 184, 
	CountryCode_Venezuela = 185, 
	CountryCode_Vietnam = 186, 
	CountryCode_Yemen = 187,
	CountryCode_Yugoslavia = 188,
	CountryCode_Zimbabwe = 189,
	CountryCode_Zaire = 190,
	CountryCode_Zambia = 191,
	CountryCode_Canada = 192,
	CountryCode_USA = 193,
	CountryCode_Kampuchea = 194,
	CountryCode_any,
	CountryCode_unknown,
	CountryCode_error,
	CountryCode_max
} CountryCode;

/* https://en.wikipedia.org/wiki/List_of_ISO_639-1_codes */

typedef enum {
	LanguageCode_Abkhazian,
	LanguageCode_Afar,
	LanguageCode_Afrikaans,
	LanguageCode_Akan,
	LanguageCode_Albanian,
	LanguageCode_Amharic,
	LanguageCode_Arabic,
	LanguageCode_Aragonese,
	LanguageCode_Armenian,
	LanguageCode_Assamese,
	LanguageCode_Avaric,
	LanguageCode_Avestan,
	LanguageCode_Aymara,
	LanguageCode_Chinese,
	LanguageCode_Chuvash,
	LanguageCode_Cornish,
	LanguageCode_Corsican,
	LanguageCode_English,
	LanguageCode_French,
	LanguageCode_German,
	LanguageCode_Italian,
	LanguageCode_Japanese,
	LanguageCode_Korean,
	LanguageCode_Russian,
	LanguageCode_Spanish_Castilian,
	LanguageCode_Sundanese,
	LanguageCode_Swahili,
	LanguageCode_Swati,
	LanguageCode_Swedish,
	LanguageCode_Tamil,
	LanguageCode_Telugu,
	LanguageCode_Tajik,
	LanguageCode_Thai,
	LanguageCode_Traditional_Chinese,
	LanguageCode_Dutch,
	LanguageCode_max
} LanguageCode;

/* https://developers.google.com/places/web-service/supported_types */

typedef enum {
	AIPlaceType_accounting,
	AIPlaceType_airport,
	AIPlaceType_amusement_park,
	AIPlaceType_aquarium,
	AIPlaceType_art_gallery,
	AIPlaceType_atm,
	AIPlaceType_bakery,
	AIPlaceType_bank,
	AIPlaceType_bar,
	AIPlaceType_beauty_salon,
	AIPlaceType_bicycle_store,
	AIPlaceType_book_store,
	AIPlaceType_bowling_alley,
	AIPlaceType_bus_station,
	AIPlaceType_cafe,
	AIPlaceType_campground,
	AIPlaceType_car_dealer,
	AIPlaceType_car_rental,
	AIPlaceType_car_repair,
	AIPlaceType_car_wash,
	AIPlaceType_casino,
	AIPlaceType_cemetery,
	AIPlaceType_church,
	AIPlaceType_city_hall,
	AIPlaceType_clothing_store,
	AIPlaceType_convenience_store,
	AIPlaceType_courthouse,
	AIPlaceType_dentist,
	AIPlaceType_department_store,
	AIPlaceType_doctor,
	AIPlaceType_electrician,
	AIPlaceType_electronics_store,
	AIPlaceType_embassy,
	AIPlaceType_fire_station,
	AIPlaceType_florist,
	AIPlaceType_funeral_home,
	AIPlaceType_furniture_store,
	AIPlaceType_gas_station,
	AIPlaceType_gym,
	AIPlaceType_hair_care,
	AIPlaceType_hardware_store,
	AIPlaceType_hindu_temple,
	AIPlaceType_home_goods_store,
	AIPlaceType_hospital,
	AIPlaceType_insurance_agency,
	AIPlaceType_jewelry_store,
	AIPlaceType_laundry,
	AIPlaceType_lawyer,
	AIPlaceType_library,
	AIPlaceType_liquor_store,
	AIPlaceType_local_government_office,
	AIPlaceType_locksmith,
	AIPlaceType_lodging,
	AIPlaceType_meal_delivery,
	AIPlaceType_meal_takeaway,
	AIPlaceType_mosque,
	AIPlaceType_movie_rental,
	AIPlaceType_movie_theater,
	AIPlaceType_moving_company,
	AIPlaceType_museum,
	AIPlaceType_night_club,
	AIPlaceType_painter,
	AIPlaceType_park,
	AIPlaceType_parking,
	AIPlaceType_pet_store,
	AIPlaceType_pharmacy,
	AIPlaceType_physiotherapist,
	AIPlaceType_plumber,
	AIPlaceType_police,
	AIPlaceType_post_office,
	AIPlaceType_real_estate_agency,
	AIPlaceType_restaurant,
	AIPlaceType_roofing_contractor,
	AIPlaceType_rv_park,
	AIPlaceType_school,
	AIPlaceType_shoe_store,
	AIPlaceType_shopping_mall,
	AIPlaceType_spa,
	AIPlaceType_stadium,
	AIPlaceType_storage,
	AIPlaceType_store,
	AIPlaceType_subway_station,
	AIPlaceType_synagogue,
	AIPlaceType_taxi_stand,
	AIPlaceType_train_station,
	AIPlaceType_transit_station,
	AIPlaceType_travel_agency,
	AIPlaceType_university,
	AIPlaceType_veterinary_care,
	AIPlaceType_zoo,

	AIPlaceType_max = 0x1fffffffffffffff
} AIPlaceType;

typedef enum {
	PythonFun_painting_aesthetics = 0,
	PythonFun_image_search_engine,
	PythonFun_painting_recommend,
	PythonFun_style_transfer,
	PythonFun_sculptures_search_engine,
	PythonFun_menu_recognition,
	PythonFun_travel_aesthetics,
	PythonFun_weichat_openid,
	PythonFun_poster,
	PythonFun_bagword,
	PythonFun_museum_recommend,
	PythonFun_painting_recommend_page,
	PythonFun_museum_recommend_page,
	PythonFun_refresh_recommend_cache,
	PythonFun_detection,
	PythonFun_generator,
	PythonFun_max = 0x1fffffffffffffff
} PythonFun;

typedef enum {
	IOStackType_uip,
	IOStackType_uip2,
	IOStackType_json,
	IOStackType_h5_form,
	IOStackType_weichat_form,
} IOStackType;

typedef enum {
	DaveDataType_char,
	DaveDataType_int,
	DaveDataType_float,
	DaveDataType_double,
} DaveDataType;

#endif

