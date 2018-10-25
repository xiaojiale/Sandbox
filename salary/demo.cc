#include "beta.h"

int main()
{
  //  int flag = 1;
  //  while(flag) {
  cout << "Please input your pre-fix wages: ";
  cin >> baseSalary;

  cout << "Have any particular conditions? (Y/N): ";
  char option = getchar();
  cout << endl;
  if (option == 'n'|| option == 'N') {
    housingFundBase = baseSalary;
    socialBenefitsBase = baseSalary;
    housingFundRatio = 0.1;
    supplementaryHousingFundRatio = 0.046;
    other = 126.53;
  }
  else {
    cout << "housingFundBase and socialBenefitsBase are full payment? (Y/N): ";
    //    cin.clear();
    //    cin.sync();
    //    char ret = getchar();
    option = getchar();
    switch(option)
    {
      case 'Y':
      case 'y':
        housingFundBase = baseSalary;
        socialBenefitsBase = baseSalary;
        break;
      case 'N':
      case 'n':
        cout << "Please input your housingFundBase: ";
        cin >> housingFundBase;

        cout << "Please input your socialBenefitsBase: ";
        cin >> socialBenefitsBase;
        break;
      default:
        cout << "ERROR" << endl;
    }

    cout << "Please input your housingFundRatio: ";
    cin >> housingFundRatio;

    cout << "Have supplementary housingFund? (Y/N): ";
    option = getchar();
    if(option == 'y'||option == 'Y') {
      cout << "Please input your supplementaryHousingFundRatio: ";
      cin >> supplementaryHousingFundRatio;
    }
    else
      supplementaryHousingFundRatio = 0;

    cout << "Have other income? (Y/N): ";
    option = getchar();
    if(option == 'y'||option == 'Y') {
      cout << "Please input the amount of other income: ";
      cin >> other;
    }
    else
      other = 0;
  }

  //  while(1)
  //  {
  //    cin >> taxableAmount;
  cout << "New calculate method? (Y/N): ";
  option = getchar();
  if(option == 'y'||option == 'Y') {
    calcTaxes2();
  }
  else {
    calcTaxes();
  }
  //  cin.clear();
  //  cin.sync();
  //  setbuf(stdin, NULL);
  //  setbuf(stdout, NULL);
  //  }

  print();

  //  if(flag) {
  //    cout<<"   是否继续？ 1.继续  0.停止  ： "<<endl;
  //    cin>>flag;
  //  }
  //  else flag=0;
  //  cout<<endl;
  //  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////
///
///    @brief Description for the calculation method of the individual income tax
///    @param[in] taxableAmount The amount of the taxable payments
///    @param[out] taxesAmount The amount of the taxes
///
////////////////////////////////////////////////////////////////////////////////
void calcTaxes()
{

  housingFund = housingFundBase * housingFundRatio;
  pension = socialBenefitsBase * 0.08;
  medicalInsurance = (socialBenefitsBase != 0 ? (socialBenefitsBase * 0.02 + 10) : 0);
  unemployment = socialBenefitsBase * 0.005;
  total_deduction_without_taxes = housingFund + medicalInsurance + pension + unemployment;

  if (baseSalary - total_deduction_without_taxes <= TAXFREE)
    taxableAmount = 0;
  else
    taxableAmount = baseSalary + other - total_deduction_without_taxes - TAXFREE;

  if(taxableAmount < 1500)
    taxesAmount = taxableAmount * 0.03;
  else if (taxableAmount >= 1500 && taxableAmount < 4500)
    taxesAmount = taxableAmount * 0.10 - 105;
  else if (taxableAmount >= 4500 && taxableAmount < 9000)
    taxesAmount = taxableAmount * 0.20 - 555;
  else if (taxableAmount >= 9000 && taxableAmount < 35000)
    taxesAmount = taxableAmount * 0.25 - 1005;
  else if (taxableAmount >= 35000 && taxableAmount < 55000)
    taxesAmount = taxableAmount * 0.30 - 2755;
  else if (taxableAmount >= 55000 && taxableAmount < 80000)
    taxesAmount = taxableAmount * 0.35 - 5505;
  else if (taxableAmount >= 80000)
    taxesAmount = taxableAmount * 0.45 - 13505;
  else
    cout << "ERROR" << endl;

  totalDeduction = total_deduction_without_taxes + taxesAmount;
  afAmount = baseSalary - totalDeduction;

  supplementaryHousingFund = housingFundBase * supplementaryHousingFundRatio;
  medicalInsuranceIncome = socialBenefitsBase * 0.03;
  //  housingFundIncome = housingFund * 2 + supplementaryHousigFund;
}

////////////////////////////////////////////////////////////////////////////////
///
///    @brief Description for the new calculation method of the individual income tax
///    @param[in] taxableAmount The amount of the taxable payments
///    @param[out] taxesAmount The amount of the taxes
///
////////////////////////////////////////////////////////////////////////////////
void calcTaxes2()
{

  housingFund = housingFundBase * housingFundRatio;
  pension = socialBenefitsBase * 0.08;
  medicalInsurance = (socialBenefitsBase != 0 ? (socialBenefitsBase * 0.02 + 10) : 0);
  unemployment = socialBenefitsBase * 0.005;
  total_deduction_without_taxes = housingFund + medicalInsurance + pension + unemployment;

  if (baseSalary - total_deduction_without_taxes <= NEWTAXFREE)
    taxableAmount = 0;
  else
    taxableAmount = baseSalary + other - total_deduction_without_taxes - NEWTAXFREE;

  if(taxableAmount <= 3000)
    taxesAmount = taxableAmount * 0.03;
  else if (taxableAmount > 3000 && taxableAmount <= 12000)
    taxesAmount = taxableAmount * 0.10 - 210;
  else if (taxableAmount > 12000 && taxableAmount <= 25000)
    taxesAmount = taxableAmount * 0.20 - 1410;
  else if (taxableAmount > 25000 && taxableAmount <= 35000)
    taxesAmount = taxableAmount * 0.25 - 2660;
  else if (taxableAmount > 35000 && taxableAmount <= 55000)
    taxesAmount = taxableAmount * 0.30 - 4410;
  else if (taxableAmount > 55000 && taxableAmount <= 80000)
    taxesAmount = taxableAmount * 0.35 - 7160;
  else if (taxableAmount > 80000)
    taxesAmount = taxableAmount * 0.45 - 15160;
  else
    cout << "ERROR" << endl;

  totalDeduction = total_deduction_without_taxes + taxesAmount;
  afAmount = baseSalary - totalDeduction;

  supplementaryHousingFund = housingFundBase * supplementaryHousingFundRatio;
  medicalInsuranceIncome = socialBenefitsBase * 0.03;
  //  housingFundIncome = housingFund * 2 + supplementaryHousigFund;
}

////////////////////////////////////////////////////////////////////////////////
///
///    @brief Description for the calculation method of the individual income tax
///
////////////////////////////////////////////////////////////////////////////////
void print()
{
  cout.setf(ios::fixed);

  // setw() is used to set the width that align to.
  // left/internal/right used to define the which side to align to.
  cout << "=============================================" << endl;
  cout << left << setw(20) << "Pre-tax Wages:"           << right << setw(25) << setprecision(2) << baseSalary << endl;
  cout << "---------------------------------------------" << endl;
  cout << left << setw(20) << "Housing Fund:"          << right << setw(25) << setprecision(2) << -1 * housingFund << endl;
  cout << left << setw(20) << "Pension:"            << right << setw(25) << setprecision(2) << -1 * pension << endl;
  cout << left << setw(20) << "Social Medical Insurance:"              << right << setw(20) << setprecision(2) << -1 * medicalInsurance << endl;
  cout << left << setw(20) << "Unemployment:"              << right << setw(25) << setprecision(2) << -1 * unemployment << endl;
  cout << left << setw(20) << "Pre-tax Deduction:" << right << setw(25) << setprecision(2) << -1 * total_deduction_without_taxes << endl;
  //  cout << left << setw(20) << "taxableAmount:"      << right << setw(25) << setprecision(2) << taxableAmount << endl;;
  cout << left << setw(20) << "Individual Income Tax:"        << right << setw(23) << setprecision(2) << -1 * taxesAmount << endl;
  cout << left << setw(20) << "Total Deduction:" << right << setw(25) << setprecision(2) << -1 * totalDeduction << endl;
  cout << "---------------------------------------------" << endl;
  cout << left << setw(20) << "After-tax Wages:"           << right << setw(25) << setprecision(2) << afAmount << endl;
  cout << "---------------------------------------------" << endl;
  cout << left << setw(20) << "Medical Insurance Income:"        << right << setw(20) << setprecision(2) << medicalInsuranceIncome << endl;
  cout << left << setw(20) << "Housing Fund Income:"          << right << setw(25) << setprecision(2) << housingFund * 2 << endl;
  cout << left << setw(20) << "Supplementary Housing Fund Income:"          << right << setw(11) << setprecision(2) << supplementaryHousingFund << endl;
  cout << left << setw(20) << "Total Benefits:"     << right << setw(25) << setprecision(2) << housingFund * 2 + supplementaryHousingFund + medicalInsuranceIncome + afAmount << endl;
  cout << "=============================================" << endl;
}
