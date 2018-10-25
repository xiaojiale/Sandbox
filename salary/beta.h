#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>

#define TAXFREE 3500
#define NEWTAXFREE 5000

using namespace std;

double baseSalary,
       other,
       housingFund,
       pension,
       medicalInsurance,
       unemployment,
       total_deduction_without_taxes,
       taxableAmount,
       taxesAmount,
       totalDeduction,
       housingFundBase,
       socialBenefitsBase,
       housingFundRatio,
       afAmount,
       supplementaryHousingFundRatio,
       supplementaryHousingFund,
//       housingFundIncome,
       medicalInsuranceIncome;

void calcTaxes();
void calcTaxes2();
void print();
